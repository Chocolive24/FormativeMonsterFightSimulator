# MonsterFightSimulator

This is a formative exercise of the Sae institute Geneva.  
The aim of the exercise was to create a monster fight simulator.  

You can create monsters by choosing their attributes and name.  
Then you can make battle between monsters you created.  

# Basics element requiered in the program :  
* Write a program that simulates the fight between two monsters. For this two monsters are to be created with the help of object-oriented programming.  
* Create a class that represents a monster. This monster must have at least the following attributes: Health Points (HP), Attack Damage (AD), Defense Points (DP), Speed (S) and Race. Possible races are orc, troll and goblin. All monsters have a method to attack, which should be called Attack.  
* At the beginning the program shall ask for an input to determine which two monsters shall fight against each other. This is realized by integer values (1 = Orc, 2 = Troll, 3 = Goblin) followed by 4 float values to determine the above mentioned attributes, which the user can enter himself. The order HP - AD - DP - S has to be followed. The program must not allow a fight between monsters of the same race.  
* Afterwards the program calculates who wins the fight. The formula for this is: Damage = Attack Damage - Defense Points. If the damage is negative, it will be set to 0. The damage is subtracted from the life points of the respective monster. If the monster still has life points left after an attack, it will now perform an attack. This is repeated until a monster dies.  
* The complete attack mechanics is realized by the attack method. The monster with the higher speed value performs the first attack. After a monster is defeated, the program displays who won and how many rounds the fight lasted. Each attack counts as a round.  
* Before you start, create a schedule in the form of a table with 3 columns. On this table write down the milestones of your planned implementation in the first column. In the second column, write down how long you think it will take you to complete each milestone. As you work, measure your time. When the milestone is completed, write in the third column how long it actually took you.  

# Learning objectives :  
* Describe the principles of object-oriented programming
* Produce stable code using object-oriented programming
* Plan and manage the allocated time to successfully meet given milestones and deadlines

# Schedule

| Milestone | Planned time | Actual time |
| --- | --- | --- |
| Create the Monster Class and instances with attributs to test the objects| 1h | 25min |
| Create the Monster Methods | 3h | 3h45 |
| Create the Menu in the Game Class | 2h30 | 4h10 |
| Create the Battle system in the the Game Class | 3h | 4h |
| Improve the game | 5h | 3h |
| Create the Monster collection | 1h | 2h30 |
| Add Music | 1h | 1h30 |
| Comment and clean the code | 2h | 1h45min |
