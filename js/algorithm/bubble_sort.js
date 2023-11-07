function bubbleSort(array) {
    const n = array.length;
  for (var i = 0; i < n; i++) {
    for(var j = 0;j<n;j++){
        if(array[j] > array[j+1]){
            var temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
        }
    }
  }
  return array;
}

const array = [3, 6, 1, 7, 5];
bubbleSort(array);
console.log(array);
