# 앱

## 사용 알고리즘 : 배낭 문제

### 문제 설명

앱 Ai는 메모리 mi를 차지하고 끄기 위해서 비용 ci가 필요하다.

M이상의 메모리를 확보하기 위해서 드는 최소 비용을 출력하는 문제

### 풀이 설명

dp배열을 다음과같이 정의하자.

dp[i] : i비용을 사용했을 때 끌 수 있는 최대 메모리

각 앱들을 돌면서 껐을 때 비용을 기준으로 확보할 수 있는 최대 메모리를 업데이트 해주면 된다.


### 시간복잡도 : N^2

전체 앱(N)을 돌면서 확인하고, 각각에 대해서 최대 비용만큼(N개 앱 * 최대 비용 100 = 100N) 반복문을 실행해야 한다.

### 어려웠던 점

단순히 생각하면 메모리크기로 배낭문제를 풀어야할 것 같은데 그러면 MK가 10억이 넘어간다.

발상을 전환해서 앱을 끄는데 필요한 비용을 dp로 잡고 문제를 풀어야 된다.