// Rafaela Lomboy
// main.cpp
// Unit Test class
// Description: Performs equality tests on other classes.

#include <iostream>
#include <string>
using namespace std;

class UnitTester {
private:
  static const int WIDTH = 50;    // char width to display on console
  static const string RED, GRN,  // change text color and bold
                      UL,         // underlines white text
                      RST;        // reset to default color
  string tTitle;      // name of test (usually has class name if testing class)
public:
  UnitTester(string str);
  void static tEqual(string msg, int cVal, int tVal);
  void static tEqual(string msg, string cVal, string tVal);
  void title();
  void subTitle(string str);
  void classTest();
};

const string UnitTester::RED = "\033[1;31m";  // color text bold red
const string UnitTester::GRN = "\033[1;32m";  // color text bold green
const string UnitTester::UL = "\033[4;37m";   // underlines white text
const string UnitTester::RST = "\033[0m";     // reset to default text settings

UnitTester::UnitTester(string str = "Performing Unit Test") : tTitle(str) { }

void UnitTester::tEqual(string msg, int cVal, int tVal) {
// This method performs equality tests on ints (can take boolean too).
// msg = test message, cVal = correct value to compare, tVal = test value

  int msgLen = msg.length();    // length of message
  string testRes,               // pass or fail test result and labels
         testP = GRN + "Pass" + RST,
         testF = RED + "Fail" + RST;

  // label for test
  cout << msg << string(WIDTH - msgLen, '.');

  // test equality and print result
  testRes = (tVal == cVal) ? testP : testF;
  cout << testRes << endl;
}

void UnitTester::tEqual(string msg, string cStr, string tStr) {
// This method performs equality tests (msg = display test message,
// cStr = correct value to compare, tStr = test value).

  int msgLen = msg.length();    // length of message
  string testRes,               // pass or fail test result and labels
         testP = GRN + "Pass" + RST,
         testF = RED + "Fail" + RST;

  // label for test
  cout << msg << string(WIDTH - msgLen, '.');

  // test equality and print result
  testRes = (tStr == cStr) ? testP : testF;
  cout << testRes << endl;
}

void UnitTester::title() {
// Prints out title/header for overall test.
  cout << tTitle << endl << string(WIDTH + 4, '-') << endl;
}

void UnitTester::subTitle(string str) {
// Prints out title for using entered string (usually for labelling  subtests
// of one method, or pass/fail testing).
  cout << UL << str << RST << endl;
}

void UnitTester::classTest() {

  UnitTester eqTest("Testing UnitTester class"); // for performing equality tests

  eqTest.title();

  // testing if tEqual method shows pass
  eqTest.subTitle("Passing Tests");
  eqTest.tEqual("tEqual(str, int, int)", 4, 4);
  eqTest.tEqual("tEqual(str, str, str)", "korra", "korra");

  // // testing if tEqual method shows fail
  eqTest.subTitle("\nFailing Tests (these should fail!)");
  eqTest.tEqual("tEqual(str, int, int)", 4, 5);
  eqTest.tEqual("tEqual(str, str, str)", "avatar", "korra");

  cout << "\nEnd of UnitTester class tests.\n\n";
}


int main()
{
  UnitTester tester;

  tester.classTest();

  return 0;
}
