const {integral, trapezoid, simpson} = require('./integral');
const EPS = 0.000001;

describe('integral function', () => {
  let method;
  let func;
  let p;

  describe('trapezoid method', () => {
    method = trapezoid;
    p = 2;
    test('test case #1', () => {
      func = (x) => 2 * x;
      expect(integral(method)(func, 0, 2, p, EPS).result).toEqual(4);
    });

    test('test case #2', () => {
      func = () => 0;
      expect(integral(method)(func, 1, 2, p, EPS).result).toEqual(0);
    });

    test('test case #3', () => {
      func = (x) => Math.pow(x, 2);
      expect(integral(method)(func, 0, 3, p, EPS).result).toEqual(9);
    });

    test('test case #4', () => {
      func = (x) => x;
      expect(integral(method)(func, 2, 10, p, EPS).result).toEqual(48);
    });
  });

  describe('simpson method', () => {
    method = simpson;
    p = 4;
    test('test case #1', () => {
      func = () => 2 * 2;
      expect(integral(method)(func, 0, 2, p, EPS).result).toEqual(8);
    });

    test('test case #2', () => {
      func = (x) => 1 + Math.pow(x, 2);
      expect(integral(method)(func, 0, 3, p, EPS).result).toEqual(12);
    });

    test('test case #3', () => {
      func = (x) => x;
      expect(integral(method)(func, 6, 10, p, EPS).result).toEqual(32);
    });
  });
});
