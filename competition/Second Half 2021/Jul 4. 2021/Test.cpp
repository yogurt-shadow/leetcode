
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_LEN = 1004; //Notice, the test data is wrong.
                          //The bound is 1004 but not 1000.
const int MAX_STR = 100;

struct SubStr
{
    const char *addr;
    int num;
};

char g_str[MAX_STR][MAX_LEN + 1];
int g_strCnt;
SubStr g_subStr[MAX_STR * MAX_LEN];
int g_subStrCnt;

int subStrCmp(const void *a, const void *b)
{
    return strcmp(((const SubStr *)a)->addr, ((const SubStr *)b)->addr);
}

int commonLen(const SubStr &a, const SubStr &b)
{
    const char *i = a.addr;
    const char *j = b.addr;
    int len = 0;
    while (*i && *j && *i == *j)
    {
        len++;
        i++;
        j++;
    }
    return len;
}

void printStr(const char *str, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", *str);
        str++;
    }
    printf("\n");
}

void initSubStr()
{
    g_subStrCnt = 0;
    for (int i = 0; i < g_strCnt; i++)
    {
        for (const char *j = g_str[i]; *j; j++)
        {
            g_subStr[g_subStrCnt].addr = j;
            g_subStr[g_subStrCnt].num = i;
            g_subStrCnt++;
        }
    }
    qsort(g_subStr, g_subStrCnt, sizeof(SubStr), subStrCmp);
}

int findLongest()
{
    int longest = 0;
    SubStr *head = g_subStr;
    SubStr *tail = g_subStr;
    const SubStr *end = g_subStr + g_subStrCnt;
    int half = g_strCnt / 2;
    int coverCnt = 0;
    int cover[MAX_STR];
    memset(cover, 0, sizeof(cover));
    while (head != end)
    {
        //To find every pair of head and tail,
        //that in the range [tail, head] there are exactly half + 1
        //strings are covered.
        while (coverCnt <= half && head != end)
        {
            if (cover[head->num] == 0)
            {
                coverCnt++;
            }
            cover[head->num]++;
            head++;
        }
        while (coverCnt > half)
        {
            cover[tail->num]--;
            if (cover[tail->num] == 0)
            {
                coverCnt--;
            }
            tail++;
        }
        if (coverCnt == half)
        {
            int len = commonLen(*(tail - 1), *(head - 1));
            if (len > longest)
            {
                longest = len;
            }
        }
    }
    return longest;
}

//The work flow of this function is just like "findLongest()".
void printCommon(int longest)
{
    const SubStr *head = g_subStr;
    const SubStr *tail = g_subStr;
    const SubStr *pre = NULL;
    const SubStr *const end = g_subStr + g_subStrCnt;
    int half = g_strCnt / 2;
    int coverCnt = 0;
    int cover[MAX_STR];
    memset(cover, 0, sizeof(cover));
    while (head != end)
    {
        while (coverCnt <= half && head != end)
        {
            if (cover[head->num] == 0)
            {
                coverCnt++;
            }
            cover[head->num]++;
            head++;
        }
        while (coverCnt > half)
        {
            cover[tail->num]--;
            if (cover[tail->num] == 0)
            {
                coverCnt--;
            }
            tail++;
        }
        if (coverCnt == half)
        {
            int len = commonLen(*(tail - 1), *(head - 1));
            if (len == longest && (pre == NULL || commonLen(*(tail - 1), *pre) < longest))
            {
                printStr((tail - 1)->addr, longest);
                pre = tail - 1;
            }
        }
    }
}

bool input()
{
    bool hasNext = false;
    scanf("%d", &g_strCnt);
    if (g_strCnt > 0)
    {
        hasNext = true;
        for (int i = 0; i < g_strCnt; i++)
        {
            scanf("%s", g_str[i]);
        }
    }
    return hasNext;
}

void solve()
{
    initSubStr();
    int len = findLongest();
    if (len == 0)
    {
        printf("?\n");
    }
    else
    {
        printCommon(len);
    }
}

int main()
{
    int cnt = 0;
    while (input())
    {
        if (cnt > 0)
        {
            printf("\n");
        }
        solve();
        cnt++;
    }
    return 0;
}