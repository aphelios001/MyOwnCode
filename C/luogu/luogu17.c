#include <stdio.h>
#include <limits.h>

int main() {
    // 输入变量x的取值范围
    long long int x1, x2;
    scanf("%lld %lld", &x1, &x2);

    // 输入变量y的取值范围
    long long int y1, y2;
    scanf("%lld %lld", &y1, &y2);

    // 判断y的取值范围是否可能超过int类型的表示范围
    if (y1 * x1 < -2147483648 || y1 * x2 > 2147483648 ||
        y2 * x1 < -2147483648 || y2 * x2 > 2147483648 ||
        y1 * x1 > 2147483648 || y1 * x2 < -2147483648 ||y2 * x1 > 2147483648
        ||y2 * x2 < -2147483648) 
        {
        printf("long long int\n");
    } else {
        printf("int\n");
    }

    return 0;
}
