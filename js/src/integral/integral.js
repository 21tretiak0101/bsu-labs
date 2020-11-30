const abs = Math.abs;
const pow = Math.pow;

/**
 * Integration method using Trapezoidal Rule.
 *
 * @param func - integration function
 * @param a - point at the start of the function graph
 * @param b - point at the end of the function graph
 * @param n - subdivisions of the function, it is an even number
 * @return {*}
 */
function trapezoid(func, a, b, n) {
  let value = func(a) + func(b);
  let sum = 0;
  let h = (b - a) / n;
  for (let i = 1; i < n; i++) {
    sum += 2 * func(a + i * h);
  }
  value += sum;
  value *= h / 2;
  return value;
}

/**
 * Integration method based on Simpson's Rule.
 *
 * @param func - integration function
 * @param a - point at the start of the function graph
 * @param b - point at the end of the function graph
 * @param n - subdivisions of the function, it is an even number
 * @return {*}
 */
function simpson(func, a, b, n) {
  let value = func(a) + func(b);
  let sum = 0;
  let h = (b - a) / n;
  for (let i = 1; i < n; i++) {
    if (i % 2 !== 0) {
      sum += 4 * func(a + i * h);
    } else {
      sum += 2 * func(a + i * h);
    }
  }
  value += sum;
  value *= h / 3;
  return value;
}

/**
 * Calculate integral using {@param method} integration method.
 *
 * @param method - integration method {@see trapezoid, @see simpson}
 * @return {function(*=, *=, *=, *=, *): {result: number, steps: number}}
 */
function integral(method) {
  let steps = 1;
  let previousValue = 0;
  return function(func, a, b, p, eps) {
    let value = method(func, a, b, steps);
    while (abs(previousValue - value) >= (pow(2, p) - 1) * eps) {
      if (p === 4 && steps % 2 !== 0) {
        steps = steps * 2;
      }
      previousValue = value;
      steps = steps * 2;
      value = method(func, a, b, steps);
    }
    return {
      result: value,
      steps
    };
  }
}

/*
Example:

    const func = (x) => 2 * x;
    integral(trapezoid)(func, 0, 10, 2, EPS);
    integral(simpson)(func, 0, 10, 4, EPS);
*/

module.exports = {
  integral,
  simpson,
  trapezoid
}
