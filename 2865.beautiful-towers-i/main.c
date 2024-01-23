long long maximumSumOfHeights(int *maxHeights, int maxHeightsSize) {
  long long ret = 0;
  for (int i = 0; i < maxHeightsSize; i++) {
    long long tmp = maxHeights[i];
    for (int j = i - 1, pre = maxHeights[i]; j >= 0; j--) {
      pre = pre > maxHeights[j] ? maxHeights[j] : pre;
      tmp += pre;
    }
    for (int j = i + 1, pre = maxHeights[i]; j < maxHeightsSize; j++) {
      pre = pre > maxHeights[j] ? maxHeights[j] : pre;
      tmp += pre;
    }
    ret = ret > tmp ? ret : tmp;
  }
  return ret;
}
