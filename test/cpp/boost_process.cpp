#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace boost;

bool load_dict(unordered_map<std::string, double> &model_map) {
  ifstream is("delay_click_model.txt");
  char buffer[1000];
  string line;
  while (is.peek() != EOF) {
    is.getline(buffer, 1000);
    line = buffer;
    vector<string> destination;
    boost::split(destination, line, boost::is_any_of("\t"),
                 boost::token_compress_on);
    if (destination.size() != 2) {
      cout << "load dict error." << line << "\t" << destination.size() << endl;
      return false;
    }

    double weight = lexical_cast<double>(destination[1]);
    model_map[destination[0]] = weight;
  }
  is.close();

  return true;
}
double compute_ctr(string line,
                   const unordered_map<string, double> &model_map) {
  vector<string> destination;
  boost::split(destination, line, boost::is_any_of("\t"),
               boost::token_compress_on);
  if (destination.size() <= 1) {
    return -1.0;
  } else {
    double w_sum = 0.0;
    for (vector<string>::iterator iter = destination.begin();
         iter != destination.end(); iter++) {
      auto search = model_map.find(*iter);
      if (search != model_map.end())
        w_sum += search->second;
    }
    return 1.0 / (1.0 + exp(-1.0 * w_sum));
  }
  return -1.0;
}
int main() {
  unordered_map<std::string, double> model_map;
  if (!load_dict(model_map)) {
    return -1;
  }
  cout << "model dimension: " << model_map.size() << endl;
  /*
  for(unordered_map<std::string, double>::iterator iter = model_map.begin();
  iter != model_map.end(); iter++) { cout << iter->first << "\t" << iter->second
  << endl;
  }
  */
  string str;
  while (getline(cin, str)) {
    double ctr = compute_ctr(str, model_map);
    cout << ctr << "\t" << str << endl;
  }

  return 0;
}
