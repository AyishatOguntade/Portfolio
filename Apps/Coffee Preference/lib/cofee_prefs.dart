import 'package:flutter/material.dart';
import 'package:flutter_masterclass/styled_body_text.dart';
import 'package:flutter_masterclass/styled_button.dart';

//start here Video 2.5.2: Watch: Buttons & Press Events [6:56]

class CoffeePrefs extends StatefulWidget {
  const CoffeePrefs({super.key});

  @override
  State<CoffeePrefs> createState() => _CoffeePrefsState();
}

class _CoffeePrefsState extends State<CoffeePrefs> {
  int strength = 1;
  int sugars = 1;

  void increaseStrength() {
    setState(() {
      strength = strength < 5 ? strength + 1 : 1;
    });
  }

  void increaseSugars() {
    setState(() {
      sugars = sugars < 5 ? sugars + 1 : 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    return Column(children: [
      Row(children: [
        StyledBodyText('Strength: '),

        for (int i = 0; i < strength; i++)
          Image.asset(
            'assets/img/coffee_bean.png',
            width: 25,
            color: Colors.brown[100],
            colorBlendMode: BlendMode.multiply,
          ),
        Expanded(child: SizedBox()),
        StyledButton(
          onPressed: increaseStrength,
          child: const Text('+'),
        ),
      ]),
      Row(children: [
        StyledBodyText('Sugar: '),
        if(sugars == 0 )
          const StyledBodyText('No sugars...'),
        for (int i = 0; i < sugars; i++)
          Image.asset('assets/img/sugar_cube.png',
            width: 25,
            color: Colors.brown[100],
            colorBlendMode: BlendMode.multiply,
          ),
        Expanded(child: SizedBox()),
        StyledButton(
          onPressed: increaseSugars,
          child: const Text('+'),
        )
      ]),
    ]);
  }
}
