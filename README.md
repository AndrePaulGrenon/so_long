# so_long

PROJET DU TROISIÈME CERCLE DE L'ÉCOLE 42 Québec. 

Le projet consiste à effectuer un petit jeu vidéo écrit en C en utilisant la librairie graphique de l'école, la Minnilibx, a very simple graphic librairy.

Le projet utilise des images pixel_art originales créés via Aseprite. Chaque sprite fait 64x64. La librairie transforme les images .xpm , fonction mlx_xpm_file_to_image, en ensembles de pixels pouvant être imprimés dans la fenêtre via la fonction mlx_put_image_to_window. 

Le programme prend en argument une carte/map utilisée pour définir le niveau du jeu. Il faut gérer les cartes non-fonctionnelles. Plusieurs cartes sont inclues dans le répertoire maps/. Recommandé : map.ber

Pour utiliser (seulement sur mac) :
            
            git clone "Https//.."
            
            make && ./so_long maps/map.ber
            
Sur Linux :
- Suivre les premières instructions de la documentations de la MLX
https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
- IL faut installer les packages et changer les flags du Makefile.
Le jeu n'a pas été créé pour linux, les animations seront trop rapides, la transparence ne sera pas prise en compte. D'autres bugs peuvent exister. 


MOUVEMENTS:   WASD         EXIT : ESC

OBJECTIFS:
  - RÉCOLTER TOUT LES CHAMPIGNONS RESTANT
  - REVENIR À LA TENTE (sortie)

  Les cartes doivent contenir :
  - Des murs '1' tout autours
  - Un joueur 'P'
  - Une sortie 'E' 
  - Un collectionnable 'C' 
  - Finir par le suffix .ber

  Les cartes peuvent contenir: 
  - Des routes 'R'
  - Des arbres/murs '1'
  - Jusqu'à 100 collectionables 'C'
  - Jusqu'à 10 ennemis (tanks) 'T'
  - Des espaces vides/plaines '0'

Exemple de fichier texte pouvant être une carte fonctionnelle:

1111111111111\n1000C1C0P01E1\n1000000T00001\n10001C1000001\n1111111111111
