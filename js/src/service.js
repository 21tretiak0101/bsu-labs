const fileSystem = require('fs');
const readline = require('readline');

async function readMatrixFromFile(path) {

  const lineReader = readline.createInterface({
    input: fileSystem.createReadStream(path)
  });

  const matrix = [];

  for await (const line of lineReader) {
    const row = line.split(' ').map(number => +number);
    matrix.push(row);
  }
  return matrix;
}

module.exports = readMatrixFromFile;
