const {gaussianElimination, residual} = require('./gaussian');
const readMatrixFromFile = require('../service');

describe('gaussianElimination function', () => {
  let path = '';
  test('should throw error', () => {
    path = 'src/assets/matrix_without_solution-1.txt';
    return readMatrixFromFile(path).then(matrix => {
      expect( () => {
        gaussianElimination(matrix)
      }).toThrowError(new Error("solution doesn't exist"));
    })
  })

  test('should throw error 2', () => {
    path = 'src/assets/matrix_without_solution-2.txt'
    return readMatrixFromFile(path).then(matrix => {
      expect( () => {
        gaussianElimination(matrix)
      }).toThrowError(new Error("solution doesn't exist"));
    })
  })

  test('should be equal to expected', () => {
    const data = [[1, 2, 3], [4, 5, 6]];
    const expected = [-1, 2];
    expect(gaussianElimination(data)).toEqual(expected);
  })
})

describe("residual function", () => {
  const matrix = [[1, 2, 3], [4, 5, 6]];
  const answers = gaussianElimination(matrix);
  test("should return 0", () => {
    expect(residual(matrix, answers)).toEqual(0);
  })
})
