const {gaussian} = require('../gaussian/gaussian');

const abs = Math.abs;
const max = Math.max;

/**
 * The derivative of a function
 *
 * @param func - function
 * @param accuracy - method accuracy
 * @return {function(*, *): number}
 */
function derivative(func, accuracy) {
  return function(args, varNumber) {
    const increment = [...args];
    increment[varNumber] = args[varNumber] + accuracy;
    const decrement = [...args];
    decrement[varNumber] = args[varNumber] - accuracy;
    return (func(...increment) - func(...decrement)) / (2 * accuracy);
  };
}

const DEFAULT_LIMIT = 50;
const DEFAULT_ACCURACY = 0.00000001;
const DEFAULT_EPSILON = 10e-9;

const DEFAULT_OPTIONS = {
  limit: DEFAULT_LIMIT,
  accuracy: DEFAULT_ACCURACY,
  eps: DEFAULT_EPSILON
};

/**
 * Newton's method for solving equations
 *
 * @param equations - (required) array with equations
 * @param approximation - (required) array with initial approximation
 * @param options - (optional) method options
 * @return {{solution: [], iterations: number}}
 */
function newton(equations, approximation, options = DEFAULT_OPTIONS) {
  let solution = [];
  let iterations = options.limit;

  const difference = [...approximation];

  for (let i = 0; i < options.limit; i++) {
    // 1. create jacobi matrix
    const jacobi = equations.reduce((matrix, equation, index) => {
      const row = [];
      for (let i = 0; i < equations.length; i++) {
        const df = derivative(equation, options.accuracy)(approximation, i);
        row.push(df);
      }
      matrix.push(row);

      difference[index] = -equation(...approximation)
      return matrix;
    }, []);

    //2. solve jacobi matrix
    const delta = gaussian(jacobi, difference);

    const previousApproximation = [...approximation];
    approximation = delta.map((el, index) => el + approximation[index]);

    //3. compute the residual vector
    const residual = max(...approximation.map((delta, index) => {
      return abs(delta - previousApproximation[index])
    }));

    //4. compute the condition number
    let conditionNumber = computeConditionNumber(difference, delta);

    if (residual < options.eps && conditionNumber < options.eps) {
      solution = [...approximation];
      iterations = i + 1;
      break;
    }
  }

  if (!solution.length) {
    throw new Error('solution not found');
  }

  return {
    solution,
    iterations
  }
}

function computeConditionNumber(difference, delta) {
  const normVector = difference.map((value, index) => {
    return abs(value) <= 1 ? abs(delta[index]) : abs(delta[index] / value);
  });
  return normVector.reduce((max, value) => {
    return value > max ? abs(value) : max;
  }, 0);
}

module.exports = {
  newton
}
