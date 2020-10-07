const abs = Math.abs;
const EPS = 0.00000001;

function getEmptyArray(length) {
  const array = [];
  for (let i = 0; i < length; i++) {
    array.push(0);
  }
  return array;
}

function createCopy(matrix) {
  const copy = [];
  matrix.forEach(row => copy.push(row));
  return copy;
}

function swapRows(matrix, rowNum1, rowNum2) {
  const buffer = matrix[rowNum1];
  matrix[rowNum1] = matrix[rowNum2];
  matrix[rowNum2] = buffer;
}

function gaussianElimination(data) {
  const matrix = createCopy(data);
  const rowsLength = matrix.length;

  for (let i = 0; i < rowsLength; i++) {
    // Search for maximum in this column
    let maxEl = abs(matrix[i][i]);
    let rowWithMaxEl = i;
    for (let j = i + 1; j < rowsLength; j++) {
      if (abs(matrix[j][i]) > maxEl) {
        maxEl = abs(matrix[j][i]);
        rowWithMaxEl = j;
      }
    }

    if (maxEl < EPS) {
      throw new Error("solution doesn't exist");
    }

    // Swap row with maximum element with current row
    if (rowWithMaxEl !== i) {
      swapRows(matrix, rowWithMaxEl, i);
    }

    // Make all rows below this one equals 0 in the current column
    for (let j = i + 1; j < rowsLength; j++) {
      const c = -matrix[j][i] / matrix[i][i];
      for (let k = i; k < rowsLength + 1; k++) {
        if (i === k) {
          matrix[j][k] = 0;
        } else {
          matrix[j][k] += c * matrix[i][k];
        }
      }
    }
  }

  const answer = getEmptyArray(rowsLength);

  // Solve equation Ax=b for an upper triangular matrix A
  for (let i = rowsLength - 1; i >= 0; i--) {
    answer[i] = matrix[i][rowsLength] / matrix[i][i];
    for (let j = i - 1; j >= 0; j--) {
      matrix[j][rowsLength] -= matrix[j][i] * answer[i];
    }
  }

  return answer;
}

function residual(matrix, answers) {
  return matrix.reduce((max, row) => {
    let leftSum = 0;
    answers.forEach((constant, index) => {
      leftSum += matrix[index] * constant;
    })
    const difference = abs(leftSum - row[row.length - 1]);
    return difference > max
        ? difference
        : max
  }, 0)
}

module.exports = {
  gaussianElimination,
  residual
}
