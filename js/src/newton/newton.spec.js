const {newton} = require('./newton');

const pow = Math.pow;
const cos = Math.cos;
const sin = Math.sin;
const pi = Math.PI;

describe("Newton's method", () => {
  let approximation = [];
  let expected = [];

  test('test case 1', () => {
    const f1 = (x, y) => x + y - 2;
    const f2 = (x, y) => 2 * x - y - 1;
    approximation = [10, -7];
    expected = [1, 1];
    expect(newton([f1, f2], approximation).solution).toEqual(expected);
  });

  test('test case 2', () => {
    const f1 = (x, y) => pow(x, 2) + pow(y, 3) + 7;
    const f2 = (x, y) => x / y + 0.5;
    approximation = [-4, 2];
    expected = [1, -2];
    expect(newton([f1, f2], approximation).solution).toEqual(expected);
  });

  test('test case 3', () => {
    const f1 = (x, y) => y * sin(x) + cos(y);
    const f2 = (x, y) => x * y - 4;
    approximation = [-4, 2];
    expect(newton([f1, f2], approximation).solution.length).toBeTruthy();
  });

  test('test case 4', () => {
    const f1 = (x, y) => pow(x, 2) + 1;
    const f2 = (x, y) => pow(y, 2) + 1;
    approximation = [-1, -1];
    expect( () => {
      newton([f1, f2], approximation);
    }).toThrowError(new Error("solution not found"));
  });

  test('test case 5', () => {
    const f1 = (x, y, z) => x * y + 1 + z * 4;
    const f2 = (x, y, z) => 4 * pow(z, 2) + cos(pi * x) + y - 3;
    const f3 = (x, y, z) => 3 * pow(x, 3) + y;
    approximation = [-1, -1, -1];
    expected = [-1, 3, 0.5];
    expect(newton([f1, f2, f3], approximation).solution).toEqual(expected);
  });

  test('test case 6', () => {
    const f1 = (x, y) => x * y + 1;
    const f2 = (x, y) => x * y + 1;
    approximation = [-1, -1];
    expect( () => {
      newton([f1, f2], approximation);
    }).toThrowError(new Error("solution doesn't exist"));
  });
});

