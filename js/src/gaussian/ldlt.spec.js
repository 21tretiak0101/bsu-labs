const {ldlt} = require('./ldlt');

describe('ldlt function', () => {
  test('should be equal to expected', () => {
    const matrix = [[2, -1, 1], [-1, 2, -1], [1, -1, 2]];
    const constants = [2.5, 0, 3.5];
    const expected = [1, 1.5, 2];
    expect(ldlt(matrix, constants)).toEqual(expected);
  })
});
