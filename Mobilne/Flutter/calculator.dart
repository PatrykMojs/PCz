import 'dart:math';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Kalkulator',
      theme: ThemeData(
        primarySwatch: Colors.blue,
      ),
      home: const Kalkulator(),
    );
  }
}

class MyButton extends StatelessWidget {
  final color;
  final textColor;
  final String buttonText;
  final VoidCallback btnFunc;

  MyButton(
      {this.color,
        this.textColor,
        required this.buttonText,
        required this.btnFunc});

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: btnFunc,
      child: Padding(
        padding: const EdgeInsets.all(8.0),
        child: ClipOval(
            child: Container(
              color: color,
              child: Center(
                  child: Text(
                    buttonText,
                    style: TextStyle(
                      color: textColor,
                      fontSize: 32,
                    ),
                  )),
            )),
      ),
    );
  }
}

class Kalkulator extends StatefulWidget {
  const Kalkulator({super.key});

  @override
  State<Kalkulator> createState() => _KalkulatorState();
}

class _KalkulatorState extends State<Kalkulator> {
  var value = '';
  var result = '';
  String a = '';
  String b = '';
  String operator = '';

  final List<String> buttons = [
    'Num',
    '/',
    '*',
    '-',
    '7',
    '8',
    '9',
    '+',
    '4',
    '5',
    '6',
    'C',
    '1',
    '2',
    '3',
    'Ent',
    '0',
    '%',
    '.'
  ];

//wykonywanie operacji matematycznych
  double operation(double x, double y, String operator) {
    if (operator == "+") {
      return x + y;
    } else if (operator == '-') {
      return x - y;
    } else if (operator == '*') {
      return x * y;
    } else if (operator == '/') {
      return x / y;
    } else if (operator == '^') {
      return pow(x, y).toDouble();
    } else if(operator=='%'){
      return x % y;
    } else {
      return 0.0;
    }
  }

  //parsownaie liczb i wywołanie metody operation
  double count(String a, String b, String operator) {
    double x = double.parse(a);
    double y = double.parse(b);
    return operation(x, y, operator);
  }

  //resetowanie
  void clear() {
    setState(() {
      a = '';
      b = '';
      value = '';
      operator = '';
    });
  }

  //sprawdzanie czy kalkulator ma dany operator
  bool isOperator(String op) {
    if (op == 'Num' ||
        op == '/' ||
        op == '*' ||
        op == '-' ||
        op == '+' ||
        op == 'C' ||
        op == 'Ent' ||
        op == '%') {
      return true;
    } else {
      return false;
    }
  }

  //funkcja przekazywania do przycisków
  _btnFunc(String btn) {
    if (isOperator(btn)) {
      if (btn == 'C') {
        clear();
      } else if (a == '') {
      } else if (a == '' && btn != '-') {
        setState(() {
          value += btn;
          a += btn;
        });
      } else if (b == '' && operator == '') {
        if (btn == "Num") {
          setState(() {
            value += '^';
            operator = '^';
          });
        } else if (a != '' && operator != '' && b != '') {
        } else {
          setState(() {
            value += btn;
            operator = btn;
          });
        }
      } else if (a != '' && operator != '' && b != '') {
        result = count(a, b, operator).toString();
        if (btn == "Num") {
          clear();
          setState(() {
            value = result + '^';
            a = result;
            operator = '^';
            result = '';
          });
        } else if (btn == "Ent") {
          clear();
          setState(() {
            value = result;
            a = result;
            result = '';
          });
        } else {
          clear();
          setState(() {
            value = result + btn;
            a = result;
            operator = btn;
          });
        }
      }
    } else {
      if (operator != '') {
        setState(() {
          value += btn;
          b += btn;
        });
      } else {
        setState(() {
          value += btn;
          a += btn;
        });
      }
    }
    print("a : ${a}, operator : ${operator}, b : ${b}");
  }

  //modelwanie przycisków służy do modelowania
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        backgroundColor: Colors.black,
        body: Column(
          children: <Widget>[
            Expanded(
              child: Container(
                alignment: Alignment.bottomCenter,
                child: Padding(
                  padding: const EdgeInsets.all(30.0),
                  child: Text(
                    value,
                    textAlign: TextAlign.center,
                    style: const TextStyle(fontSize: 40, color: Colors.white),
                  ),
                ),
              ),
            ),
            Expanded(
              flex: 2,
              child: GridView.builder(
                  itemCount: buttons.length,
                  gridDelegate: const SliverGridDelegateWithFixedCrossAxisCount(
                      crossAxisCount: 4),
                  itemBuilder: (BuildContext context, int index) {
                    return MyButton(
                      btnFunc: (() {
                        _btnFunc(buttons[index]);
                      }),
                      buttonText: buttons[index],
                      color: Colors.orange,
                      textColor: Colors.white,
                    );
                  }),
            )
          ],
        ));
  }
}
