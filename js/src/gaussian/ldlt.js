function ldlt(matrix, constants) {
  matrix.forEach((el, idx) => {
    for (let i = idx + 1; i < matrix.length; i++) {
      let sum = 0;
      for (let k = 0; k <= idx - 1; k++) {
        sum += matrix[i][k] * matrix[k][idx];
      }
      matrix[i][idx] = matrix[i][idx] - sum;
    }
    let sum = 0;
    for (let k = 0; k < idx; k++) {
      sum += el[k] * matrix[k][idx];
    }
    el[idx] -= sum;
    for (let i = idx + 1; i < matrix.length; i++) {
      el[i] = matrix[i][idx] / el[idx];
    }
  });

  const y = [];
  for (let i = 0; i < matrix.length; i++) {
    let sum = 0;
    for (let k = 0; k <= i - 1; k++) {
      sum += matrix[k][i] * y[k];
    }
    y[i] = constants[i] - sum;
  }

  const z = matrix.map((el, idx) => {
    return y[idx] / el[idx];
  });

  let answer = [];
  answer[matrix.length - 1] = z[matrix.length - 1];

  for (let i = matrix.length - 2; i >= 0; i--) {
    let sum = 0;
    for (let k = i + 1; k < matrix.length; k++) {
      sum += matrix[i][k] * answer[k];
    }
    answer[i] = z[i] - sum;
  }
  return answer.map((el) => +el.toFixed(1));
}

module.exports = {ldlt};
