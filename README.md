# Boj_ps (Baekjoon Online Judge problem solving)

1일 1알고리즘

# vscode - snippet

`pstemplate` 스닙셋을 만들어서 사용중 (자동완성)

```json
{
	"problem-solving-template": {
		"prefix": "pstemplate",
		"body": [
			"#include <bits/stdc++.h>",
			"using namespace std;",
			"",
			"static bool OOB(int x, int y, int Mx, int My)",
			"{",
			"	return (x < 0 || y < 0 || Mx <= x || My <= y);",
			"}",
			"",
			"int main() {",
			"	return 0;",
			"}",
			""
		],
		"description": "Template for problem solving."
	}
}
```

# template

`pstemplate` 스닙셋에 사용되는 템플릿 코드