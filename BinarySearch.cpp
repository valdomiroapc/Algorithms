int binSearch(vector<int> array, int element) {
  int l = 0;
  int r = array.size()-1;
  while(l<r) {
    int m = (l+r)/2;
    if (element <= array[m]) {
      r = m;
    }
    else {
      l = m+1;
    }
  }
  if (array[l] == element) {
    return l;
  }
  return -1;
}