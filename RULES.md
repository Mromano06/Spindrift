# Spindrift's Rules

Author: Matthew Romano

### Brief Overview

This is a turn-based combat game in which the player and their opponenet take turns attack with and moving their pieces.
The pieces are layed out on the gameboard that shows the pieces locations.
Each piece has different statistics: health, defence, damage, range and movement.
It is up to the player to use these pieces to defeat and capture the opponent and their pieces.
The game finishes when a player controls more than 75% of all rigs, or has destroyed all of their opponents pieces.

### How The Game Works

The players take turns moving and attacking.
Each piece can be moved once or attack once per turn.
You cannot attack with and move the same piece in the same turn.
Once you have made all moves or chose to pass your turn the turn is passed to the opponent.
Turns continue until a one player wins.

### Combat/Capturing

To destory and enemy ship or to capture an enemy rig a player must reduce that piece's health to 0.
To do this the player must use thier own ships to attack.
When within range a ship can attack an opposing ship/rig (this counts as the pieces turn).
The amount of damage depends on the defence of the opposing ship and the damage of the attacking ship (along with some minor RNG). 
Upon a ship reaching 0 health it is destroyed and removed from the board.
Upon a rig reaching 0 health it is not destroyed but captured switching to the opponents side. 

### How To Win

If a player destroys all of the oponenets ships then they automatically win.
Otherwise a player must capture 75% of the total oil rigs on the board.
In the default case 6 total rigs are placed on the board at the start of the game.
This means that to win the player must capture 5/6 of the oil rigs.

### Piece Overview

**Tug Boat**  
Health: Medium  
Defence: Medium  
Danage: Medium  
Movement: Medium  
Range: Low

**Container Ship**  
Health: High  
Defence: High  
Damage: Low  
Movement: Low  
Range: Medium  

**Speed Boat**  
Health: Low  
Defence: Low  
Damage: High  
Movement: High  
Range: High  

**Oil Rig**  
Health: Very High  
Defence: Medium  
Damage: Very Low  
Movement: N/A  
Range: Low  

### Board Overview

This still needs to be fleshed out.

### Additional Notes
While the oil rig cant move it can still fight back against attacker, although it is extremely weak.




