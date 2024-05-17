//题目内容：
//定义一个二维数组，例如：
//int maze[5][5] = {
//               0, 1, 0, 0, 0,
//               0, 1, 0, 1, 0,
//               0, 0, 0, 0, 0,
//               0, 1, 1, 1, 0,
//               0, 0, 0, 1, 0,
//};
//它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
//
//输入格式:
//一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一最短路径。
//
//输出格式：
//左上角到右下角的最短路径，格式如样例所示。
//
//输入样例：
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0
//
//输出样例：
//(0,0)
//(1,0)
//(2,0)
//(2,1)
//(2,2)
//(2,3)
//(2,4)
//(3,4)
//(4,4)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {}
};

int main() {
    int maze[5][5];
    //记录每个路径的方向
    int direction[5][5];//0-来自左侧，1-来自上方，2-来自右侧，3-来自下方
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> maze[i][j];
        }
    }
    queue<Point> q;
    q.push(Point(0, 0));
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        if (p.x == 4 && p.y == 4) {
            break;
        }
        if (p.x + 1 < 5 && maze[p.x + 1][p.y] == 0) {
            q.push(Point(p.x + 1, p.y));
            maze[p.x][p.y] = 1;
            direction[p.x + 1][p.y] = 1;
        }
        if (p.y + 1 < 5 && maze[p.x][p.y + 1] == 0) {
            q.push(Point(p.x, p.y + 1));
            maze[p.x][p.y] = 1;
            direction[p.x][p.y + 1] = 0;
        }
        if (p.x - 1 >= 0 && maze[p.x - 1][p.y] == 0) {
            q.push(Point(p.x - 1, p.y));
            maze[p.x][p.y] = 1;
            direction[p.x - 1][p.y] = 3;
        }
        if (p.y - 1 >= 0 && maze[p.x][p.y - 1] == 0) {
            q.push(Point(p.x, p.y - 1));
            maze[p.x][p.y] = 1;
            direction[p.x][p.y - 1] = 2;
        }
    }
    vector<Point> path;
    Point p(4, 4);
    path.push_back(p);
    while (p.x != 0 || p.y != 0) {
        if (direction[p.x][p.y] == 0) {
            p.y--;
        } else if (direction[p.x][p.y] == 1) {
            p.x--;
        } else if (direction[p.x][p.y] == 2) {
            p.y++;
        } else {
            p.x++;
        }
        path.push_back(p);
    }
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << "(" << path[i].x << "," << path[i].y << ")" << endl;
    }
    return 0;
}
