let eps  = 0.001;
const abs = Math.abs;
const pow = Math.pow;

function sle(arrayA, arrayB, size) {
  const array = [];
  for (let k = 0; k < size; k++) {
    let max = abs(arrayA[k][k]);
    let index = k;
    for (let i = k + 1; i < size; i++) {
      if (abs(arrayA[i][k]) > max) {
        max = abs(arrayA[i][k]);
        index = i;
      }
    }
    if (max < eps) {
      return array;
    }
    for (let j = 0; j < size; j++) {
      [arrayA[k][j], arrayA[index][j]] = [arrayA[k][j], arrayA[index][j]];
    }
    [arrayA[k], arrayB[index]] = [arrayB[index], arrayA[k]];

    for (let i = k; i < size; i++) {
      let res = arrayA[i][k];
      if (abs(res) < eps) {
        continue;
      }
      for (let j = 0; j < size; j++) {
        arrayA[i][j] /= res;
      }
      arrayA[i] /= res;
      if (i === k) {
        continue;
      }
      for (let j = 0; j < size; j++) {
        arrayA[i][j] -= arrayA[k][j];
      }
      arrayB[i] -= arrayB[k];
    }
  }
  for (let i = size - 1; i >= 0; i--) {
    array[i] = arrayB[i];
    for (let j = 0; j < i; j++)
      arrayB[j] = arrayB[j] - arrayA[j][i] * array[i];
  }
  return array;
}

function mnk(arrayA, arrayB, m, N){
  let powerA = [];
  let sumA = [];
  let values = [];
  let count;
  for (let i = 0; i < 2 * m; i++) {
    powerA[i] = arrayA.reduce((acc, value) => {
      count += pow(value, i);
    }, 0);
  }

  for (let i = 0; i < m ; i++) {
    for (let j = 0; j < m ; j++) {
      sumA[i][j] = powerA[i + j];
    }
  }

  for (let i = 0; i < m ; i++) {
    values[i] = arrayA.reduce((acc, value, index) => {
      acc = acc + value * pow(arrayB[index], index);
      return acc;
    }, 0)
  }

  const sleResult = sle(sumA, values, m);

  count = arrayA.reduce((acc, _, index) => {
    let counter = arrayB[index];
    for (let j = 0; j < m ; j++) {
      counter = counter - sleResult[j] * pow(arrayA[j], j + 1);
    }
    acc = acc + counter;
    return acc;
  }, 0);

  return Math.sqrt((1.0 / (N - m)) * count);
}
