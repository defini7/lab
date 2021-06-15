bool valid_braces(std::string s) {
    std::vector<char> stk;
    for (char c : s) {
      switch (c) {
      case '(':
      case '{':
      case '[':
        stk.push_back(c);
        break;
      case ')':
        if (stk.empty() || stk.back() != '(')
          return false;
        stk.pop_back();
        break;
      case '}':
        if (stk.empty() || stk.back() != '{')
          return false;
        stk.pop_back();
        break;
      case ']':
        if (stk.empty() || stk.back() != '[')
          return false;
        stk.pop_back();
        break;
      }
    }
    return stk.empty();
  }
