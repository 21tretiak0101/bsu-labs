const fileSystem = require('fs')

function X(x, y) {
  return  x * (0.4 - 0.01 * y);
}

function Y(x, y) {
  return  (-0.3 + 0.005 * x) * y;
}

const DEFAULT_FRACTION_DIGITS = 4;

/**
 * General solution for systems of ODEs implemented with Euler explicit method.
 *
 * [solution for Lotka–Volterra equations]
 *
 * @param equations - array with equations (2 for Lotka–Volterra)
 * @param initial - array with initial values (2 for Lotka–Volterra)
 * @param start - left integration border
 * @param limit - right integration border
 * @param h - standing integration step
 * @return {[{step: number, result: []}]}
 */
function euler(equations, initial, start, limit, h) {

  let data = (step, result) => {return {step, result}};

  const answer = [data(start, initial)];

  let previousValues = [...initial];
  for (let i = start + 1; i <= limit; i++) {
    const values = equations.map((eq, index) => {
      let value = h * eq(...previousValues) + previousValues[index];
      return +value.toFixed(DEFAULT_FRACTION_DIGITS);
    });
    answer.push(data(i, values));
    previousValues = [...values];
  }
  return answer;
}

/**
 * Write Lotka–Volterra results to a file.
 *
 * @param result - array with Lotka–Volterra results
 * @param filename - path to file
 */
function writeResults(result, filename) {
  const header = 'day, preys, predators\n';
  const data = result.reduce((str, obj) => {
    return str + obj.step + ', ' + obj.result.join(', ') + '\n';
  }, "")
  fileSystem.writeFile(filename, header + data, (err) => {
    if (err) {
      throw new Error(err.message);
    }
  });
}

//example
writeResults(euler([X, Y], [70, 50], 1, 364, 0.15), "example.txt");
