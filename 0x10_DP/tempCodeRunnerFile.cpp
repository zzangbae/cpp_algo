 확인하기
    queue<pair<int, int>> cq;
    cq.push({1, 1});
    int answer = 0;
    while(!cq.empty()) {
        answer++;
        int cx = cq.front().first;
        int cy = cq.front().second;
        cq.pop();
        for(int i = 0; i < 4; i++) {
            int cnx = cx + dx[i];
            int cny = cy + dy[i];
            if(cnx >= n || cnx < 0 || cny >= n || cny < 0) continue;
            if(arr[cnx][cny] == 0) continue;
            cq.push({cnx, cny});
        }
    }
    cout << answer;