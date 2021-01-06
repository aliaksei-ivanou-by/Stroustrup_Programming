Ax*
A
Ax
Axx
Axxxxxxxxxxxxxxxxxxxx

Ax+
Ax
Axx
Axxxxxxxxxxxxxxxxxxxx

\d-?\d
1-2
12

\w{2}-\d{4,5}
Ab-1234
XX-54321
22-54321

(\d*:)

(\d*:)?(\d+)

Subject: (FW:|Re:)?(.*)
Subject: FW: Hello, world!
Subject: Re:
Subject: Norwegian Blue

string s = "\"[[:alnum:]]+\"";
regex s1{ "\\\"[[:alnum:]]+\\\"" };
regex s2{ R"("[[:alnum:]]+")" };