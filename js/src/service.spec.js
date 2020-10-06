const readMatrixFromFile = require('./service');

describe('readMatrixFromFile function', ()=> {
  test('should be equal to expected', () => {
    const path = 'src/assets/data.txt';
    const expected = [[1, 2, 3], [4, 5, 6]];
    return readMatrixFromFile(path).then(data => {
      expect(data).toEqual(expected);
    })
  })
})
