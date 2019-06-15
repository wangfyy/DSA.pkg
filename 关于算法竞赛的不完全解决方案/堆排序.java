public void buildMaxHeap(int arr[], int len) {
	for(int i = len / 2; i > 0; i--)  //最后一个节点是第len/2个节点的孩子
		adjustDown(arr, i, len)
}
public void adjustDown(int arr[], int i, int len) {
	arr[0] = arr[i];  //暂存
	for(int j = i * 2; j <= len; j++) {  //i为根,j为i的各子代
		if(j < len && arr[j] < arr[j + 1])  //比较左右孩子的大小
			j++;
		if(arr[0] > arr[j]) break;  //退出循环
		else {
			arr[i] = arr[j];  //将j上移到双亲节点上
			i = j;  //重新选跟，以这个子代(j)为下次循环的跟
		}
	}
	arr[j] = a[0];
}

public void adjustUp(int arr[], int i) {  //i为向上调整的结点
	arr[0] = arr[i];
	int j = i / 2;  //j为双亲,i为向上的调整的起点节点
	while(j > 0 && arr[j] < arr[0]) {
		arr[i] = arr[j];
		i = j;
		j = i / 2;
	}
	arr[i] = arr[0];
}

public void heapSort(int arr[], int len) {
	buildMaxHeap(arr, len);
	for(int i = len; i > 1; i--) {
		print(arr[1]);
		swap(arr[i], arr[1]);
		adjustDown(arr, 1, i - 1);
	}
	print(arr[1]);
}