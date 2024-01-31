import 'dart:ui';
import 'package:flutter/material.dart';
import 'dart:developer';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Zadania',
      theme: ThemeData(
        primarySwatch: Colors.orange,
      ),
      home: const MyHomePage(title: 'Zadania'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key? key, required this.title}) : super(key: key);
  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {

  TextEditingController taskName = new TextEditingController();
  TextEditingController taskDiscription = new TextEditingController();
  TextEditingController taskPiority = new TextEditingController();
  var EdittaskDiscription = "";
  var EdittaskName="";
  var menu=0;
  var detalisChecked=0;
  List<String> names=[];
  List<String> description=[];
  List<int> piority=[];
  List<String> Date=[];
  void showDetalis(var a)
  {
    setState(() {
      menu=4;
      detalisChecked=a;
    });

  }

  void addToName(var a)
  {
    var b=a;
    setState(() {
      EdittaskDiscription=b;
    });
  }

  void addIcon( var a)
  {
    setState(() {
      menu=a;
    });

  }
  void specialActions(var a)
  {
    switch(a)
    {
      case 1:
        if(taskName.text!=""&&taskPiority.text!=""&&taskDiscription!=""&&(taskPiority.text=="1"||taskPiority.text=="2"||taskPiority.text=="3")) {

          var now = new DateTime.now();
          names.add(taskName.text);
          description.add(taskDiscription.text);
          piority.add(int.parse(taskPiority.text));
          Date.add(now.toString().substring(0,now.toString().length-7));
          taskPiority.text="";
          taskName.text = "";
          taskDiscription.text = "";
        }
        break;
    }
  }
  Widget addButton(String buttonText) {
    if (buttonText == "Nowe zadanie") {
      return Expanded(
        child: ElevatedButton(
          child: Text(buttonText,
              style: const TextStyle(

                fontSize: 25,
              )),
          onPressed: () => addIcon(1),
          style: ElevatedButton.styleFrom(
              primary: Colors.orange,
              padding: const EdgeInsets.symmetric(horizontal: 15, vertical: 15),
              textStyle:
              const TextStyle(fontSize: 25, fontWeight: FontWeight.bold)),
        ),
      );
    }
    if(buttonText == "Lista zadań") {
      return Expanded(
        child: ElevatedButton(
          child: Text(buttonText,
              style: const TextStyle(

                fontSize: 25,
              )),
          onPressed: () => addIcon(2),
          style: ElevatedButton.styleFrom(
              primary: Colors.orange,
              padding: const EdgeInsets.symmetric(horizontal: 15, vertical: 15),
              textStyle:
              const TextStyle(fontSize: 25, fontWeight: FontWeight.bold)),
        ),
      );
    }

    if(buttonText == "Dodaj") {
      return Expanded(
        child: ElevatedButton(
          child: Text(buttonText,
              style: const TextStyle(

                fontSize: 35,
              )),
          onPressed: () => specialActions(1),
          style: ElevatedButton.styleFrom(
              primary: Colors.orange,
              padding: const EdgeInsets.symmetric(horizontal: 15, vertical: 15),
              textStyle:
              const TextStyle(fontSize: 30, fontWeight: FontWeight.bold)),
        ),
      );
    }
    if(buttonText=="Edytuj")
    {
      return Expanded(
        child: ElevatedButton(
          child: Text(buttonText,
              style: const TextStyle(

                fontSize: 25,
              )),
          onPressed: () => addIcon(5),
          style: ElevatedButton.styleFrom(
              primary: Colors.orange,
              padding: const EdgeInsets.symmetric(horizontal: 15, vertical: 15),
              textStyle:
              const TextStyle(fontSize: 25, fontWeight: FontWeight.bold)),

        ),
      );
    }
    else {
      return Expanded(
        child: MaterialButton(
          color: Colors.orange,
          child: Text("",
              style: const TextStyle(

                fontSize: 50,
              )),
          padding: EdgeInsets.all(24.0),
          onPressed: () => addIcon(''),
        ),
      );
    }
  }

  @override
  Widget build(BuildContext context) {

    if(menu==0)
    {

      return Scaffold(
        backgroundColor: Colors.grey,
        appBar: AppBar(
          backgroundColor: Colors.orange,
          title: Text("Lista zadań"),
          centerTitle: true,
          elevation: 0,
          leading: Builder(
            builder: (BuildContext context) {
              return IconButton(
                icon: const Icon(Icons.arrow_back_sharp),
                onPressed: () =>addIcon(0) ,
                tooltip: MaterialLocalizations.of(context).previousPageTooltip,
              );
            },
          ),
        ),
        body: Container(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.spaceAround,
            children: [
              Row(
                children: [
                  Expanded(child: Container()),
                  addButton("Nowe zadanie"),
                  Expanded(child: Container()),
                ],
              ),

              Row(
                children: [
                  Expanded(child: Container()),
                  addButton("Lista zadań"),
                  Expanded(child: Container()),
                ],
              ),
            ],
          ),
        ),
        // This trailing comma makes auto-formatting nicer for build methods.
      );
    }
    else if(menu==1)
    {
      return Scaffold(
        backgroundColor: Colors.grey,
        appBar: AppBar(
          backgroundColor: Colors.orange,
          title: Text("Dodawanie zadania"),
          centerTitle: true,
          elevation: 0,
          leading: Builder(
            builder: (BuildContext context) {
              return IconButton(
                icon: const Icon(Icons.arrow_back_sharp),
                onPressed: () =>addIcon(0) ,
                tooltip: MaterialLocalizations.of(context).previousPageTooltip,
              );
            },
          ),
        ),
        body: Container(
          child: Column(
            mainAxisSize: MainAxisSize.max,
            mainAxisAlignment: MainAxisAlignment.spaceEvenly,
            children: [
              Row(
                children: [
                  Text('Nazwa zadania: ',
                      textAlign:TextAlign.end,
                      style: const TextStyle(
                        fontSize: 27,

                      )),
                ],
              ),

              TextField(
                controller: taskName,
                style: TextStyle(fontSize: 20),

                decoration: InputDecoration(
                  icon: Icon(Icons.send),
                  hintText: 'Wpisz nazwę zadania',
                  border: OutlineInputBorder(),
                  contentPadding:

                  const EdgeInsets.only(left: 14.0, bottom: 8.0, top: 8.0),

                ),
              ),
              Row(
                children: [
                  Text('Opis zadania:',
                      textAlign:TextAlign.center,
                      style: const TextStyle(
                        fontSize: 27,

                      )),
                ],
              ),

              Flexible(child:
              new TextField(
                controller: taskDiscription,
                style: TextStyle(fontSize: 20),
                decoration: InputDecoration(
                  icon: Icon(Icons.send),
                  hintText: 'Wpisz opis zadania',
                  border: OutlineInputBorder(),
                  contentPadding:
                  const EdgeInsets.only(left: 14.0, bottom: 8.0, top: 8.0),

                ),
              ),
              ),
              Row(
                children: [
                  Text('Priorytet zadania: (1-3)',
                      textAlign:TextAlign.center,
                      style: const TextStyle(
                        fontSize: 27,
                      )
                  ),
                ],
              ),

              Flexible(child:
              new TextField(
                controller: taskPiority,
                style: TextStyle(fontSize: 20),
                decoration: InputDecoration(
                  icon: Icon(Icons.send),
                  hintText: 'Wpisz  priorytet',
                  border: OutlineInputBorder(),
                  contentPadding:
                  const EdgeInsets.only(left: 14.0, bottom: 8.0, top: 8.0),
                ),
              ),
              ),
              Row(
                children: [
                  Expanded(child: Container()),
                  addButton("Dodaj"),
                  Expanded(child: Container()),
                ],
              ),

            ],
          ),
        ),
        // This trailing comma makes auto-formatting nicer for build methods.
      );
    }
    else if(menu==2)
    {
      return Scaffold(
        backgroundColor: Colors.grey,
        appBar: AppBar(
          backgroundColor: Colors.orange,
          title: Text("Lista zadań do zrobienia"),
          centerTitle: true,
          elevation: 0,
          leading: Builder(
            builder: (BuildContext context) {
              return IconButton(
                icon: const Icon(Icons.arrow_back_sharp),
                onPressed: () =>addIcon(0) ,
                tooltip: MaterialLocalizations.of(context).previousPageTooltip,
              );
            },
          ),
        ),
        body:
        ListView.builder(
          itemCount: names.length,
          itemBuilder: (context,index){
            return Card(
              child: ListTile(
                tileColor: piority[index]==1?Colors.red:piority[index]==2?Colors.yellow:Colors.green,
                onTap:()=>showDetalis(index),
                title: Text("Zadanie: "+ names[index]+"        Data dodania: "+Date[index],
                  style: const TextStyle(
                      fontSize: 22,
                      fontWeight: FontWeight.bold
                  ),
                ),
              ),
            );
          },
        ),
      );
    }
    else if(menu==4)
    {
      return Scaffold(
        backgroundColor: Colors.grey,
        appBar: AppBar(
          backgroundColor: Colors.orange,
          title: Text("Szczegóły zadania - " + names[detalisChecked]),
          centerTitle: true,
          elevation: 0,
          leading: Builder(
            builder: (BuildContext context) {
              return IconButton(
                icon: const Icon(Icons.arrow_back_sharp),
                onPressed: () =>addIcon(2) ,
                tooltip: MaterialLocalizations.of(context).previousPageTooltip,
              );
            },
          ),
        ),
        body: Container(
          child: Column(
              mainAxisAlignment: MainAxisAlignment.spaceEvenly,
              children: [
                Row(
                  children: [
                    Expanded(child: Container()),
                    Text('Opis zadania: ',
                        textAlign:TextAlign.center,
                        style: const TextStyle(
                          fontSize: 27,

                        )),
                    Expanded(child: Container()),
                  ],
                ),
                Flexible(child:
                Text(description[detalisChecked],
                    textAlign:TextAlign.center,
                    style: const TextStyle(
                        fontSize: 40,
                        fontWeight: FontWeight.bold
                    )),
                ),
                Row(
                  children: [
                    Expanded(child: Container()),
                    addButton('Edytuj'),
                    Expanded(child: Container()),
                  ],
                ),
              ]
          ),
        ),
        // This trailing comma makes auto-formatting nicer for build methods.
      );
    }
    if(menu==5){
      return Scaffold(
        backgroundColor: Colors.grey,
        appBar: AppBar(

          title: Text("Edytowanie zadania - " + names[detalisChecked]),
          centerTitle: true,
          elevation: 0,
          leading: Builder(
            builder: (BuildContext context) {
              return IconButton(
                icon: const Icon(Icons.arrow_back_sharp),
                onPressed: () =>addIcon(4) ,
                tooltip: MaterialLocalizations.of(context).previousPageTooltip,
              );
            },
          ),
        ),
        body: Container(
          child: Column(
              children: [
                Row(
                  children: [
                    Text('Edytuj nazwę zadania: ',
                        textAlign:TextAlign.center,
                        style: const TextStyle(
                          fontSize: 27,
                        )
                    ),
                  ],
                ),
                TextField(
                  controller: TextEditingController(text:names[detalisChecked]),
                  onChanged: (text)=> {names[detalisChecked]=text},

                  style: TextStyle(fontSize: 22),
                  decoration: InputDecoration(
                    icon: Icon(Icons.send),
                    hintText: 'Edytuj nazwę zadania',
                    border: OutlineInputBorder(),
                    contentPadding:

                    const EdgeInsets.only(left: 14.0, bottom: 8.0, top: 8.0),
                  ),
                ),
                Row(
                  children: [
                    Text('Edytuj opis zadania: ',
                        textAlign:TextAlign.center,
                        style: const TextStyle(
                          fontSize: 27,
                        )
                    ),
                  ],
                ),
                TextField(
                  controller: TextEditingController(text:description[detalisChecked]),
                  onChanged: (text)=> {description[detalisChecked]=text},

                  style: TextStyle(fontSize: 22),
                  decoration: InputDecoration(
                    icon: Icon(Icons.send),
                    hintText: 'Edytuj opis zadania',
                    border: OutlineInputBorder(),
                    contentPadding:

                    const EdgeInsets.only(left: 14.0, bottom: 8.0, top: 8.0),
                  ),
                ),
                Row(
                  children: [
                    Text('Edytuj priorytet zadania: (1-3)',
                        textAlign:TextAlign.center,
                        style: const TextStyle(
                          fontSize: 27,
                        )
                    ),
                  ],
                ),
                TextField(
                  controller: TextEditingController(text:piority[detalisChecked].toString()),
                  onChanged: (text)=> {piority[detalisChecked]=text==""?1:text=="1"?1:text=="2"?2:text=="3"?3:1},

                  style: TextStyle(fontSize: 22),
                  decoration: InputDecoration(
                    icon: Icon(Icons.send),
                    hintText: 'Edytuj priorytet zadania',
                    border: OutlineInputBorder(),
                    contentPadding:

                    const EdgeInsets.only(left: 14.0, bottom: 8.0, top: 8.0),
                  ),
                ),
                Row(
                  children: [
                    Expanded(child: Container()),
                    addButton('Edytuj'),
                    Expanded(child: Container()),
                  ],
                ),
              ]
          ),
        ),
        // This trailing comma makes auto-formatting nicer for build methods.
      );
    }
    else
    {
      return Scaffold();
    }

  }
}
