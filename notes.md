## Taches
Parsing map : simon
Initialisation (chargement texture, free a la fin) : yves
Gestion inputs (clavier souris) : yves
Render :

## Bonus
Collisions : yves
Minicarte : 
Portes : 
Animations : Yves
Controle pdv a la souris : Yves

## ex struct

## Ray casting

Implique une camera parallele au sol

La camera projette un rayon par pixel, la collision la plus proche de la camera defini la couleur du pixel
- >regrouper les pixel par multiple de 4 pour accelerer le rendu/baisser la qualite
- >envoyer un rayon par pixel en largeur suffit pour definir ce qu'on vois sur toute la longueur
- >la distance de collision defini la taille du mur, remplir le reste avec le sol et plafond

Un point de fuite

## controles

<- -> rotation camera
WASD deplacement
ESC X quitter

## Ressources

https://perso.esiee.fr/~buzerl/sphinx_IMA/80%20raycast/raycast.html
https://fr.wikipedia.org/wiki/Raycasting
https://lodev.org/cgtutor/raycasting.html

## Exemples

http://users.atw.hu/wolf3d/

X WIDTH
Y HEIGHT (inverse)
0<->WWIDTH
^
W
H
E
I
G
H
T