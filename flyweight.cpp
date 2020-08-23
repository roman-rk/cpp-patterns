#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <sstream>
using namespace std;

struct Sentence
{
  struct WordToken
  {
    bool capitalize;
  };
  static vector<string> extractWordsVector(string const& s)
  {
    vector<string> results;
    string buf;
    stringstream ss{s};
    while (ss >> buf)
      results.push_back(buf);
    return results;
  }
  Sentence(const string& text)
  {
    for (string word : extractWordsVector(text))
    {
      words.push_back(make_pair(word, WordToken{false}));
    }
  }

  WordToken& operator[](size_t index)
  {
    return words[index].second;
  }

  string str() const
  {
    string result;
    for (auto word : words)
    {
      result = result.empty() ? result : result + " ";
      if (word.second.capitalize == true)
      {
        for (char c: word.first)
        {
          result += toupper(c);
        }
      }
      else
      {
        result += word.first;
      }
    }
    return result;
  }

private:
  vector<pair<string, WordToken>> words;
};

int main()
{
  Sentence s{"hello world"};
  s[1].capitalize = true;
  cout << s.str();
}