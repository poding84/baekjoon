# 가장 긴 증가하는 부분 수열 5

## 사용 알고리즘 : 이분탐색

### 문제 설명

수열이 주어지고, 해당 수열의 최장 증가 부분 수열의 길이와 해당 수열을 출력한다.

### 풀이 설명

최장 증가 수열을 담을 배열을 하나 선언하고 매 원소를 검사하여 해당 배열에서 원소를 바꿔치기할지, 뒤에 붙일지만 결정해주면 된다.

전체 수열을 하나씩 방문할 때 해당 원소가 최장 증가 수열의 몇 번째에 삽입되었는지 기록해두어야 마지막에 최장 증가 부분 수열을 출력할 수 있다.

### 시간복잡도 : 

모든 원소(N)를 검사하면서 해당 원소가 업데이트될 자리를 수열에서 찾은 뒤(logN) 그 자리에 넣어주거나, 가장 마지막이라면 그냥 append해준다.

### 어려웠던 점

최장 증가 수열이 계속 변화하기 때문에 마지막에 출력할 때 어려웠다.