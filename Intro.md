# Introduction
Le but le de ce projet est de crée des véhicules télécommandés pilotés par Arduino avec lesquels nous pourront faire un « lasertag ». 
Ces véhicules seront équipés d’artillerie (émetteur) et de zone faible (récepteur), la communication entre les tanks (pour les tirs) se fera par infrarouge. Comme nos télécommande de télévision par exemple.
Mon but est de faire de ce projet une collaboration « opensource » qui nous permettra d’acquérir de nouvelle connaissance tout en s’amusant. Certaine partie sont plus compliquée que d’autre, et pour ne freiner personne, je mettrais des éléments « tous cuits » à dispositions (par ex. le programme arduino ou une liste de matériel permettant de monté un tank fonctionnelle). Cependant je vous conseille de faire le maximum par vous-même pour en apprendre le plus possible.

# Règles
En dehors de ces quelques règles tout le reste de vos choix est libre.
- Un arduino dois être au cœur de la logique.
- Une partie du code sera imposée, la modifié sera considéré comme de la triche. Ce code permet de posé un canevas sur les capacités, les armes, la vie, etc.
- Le véhicule sera équipé de récepteur IR (connecté) est d’un émetteur défini.
- Amusez-vous !

# Hardware
Liste non exhaustive du matériel utilisé lors de la création d’un premier prototype(v3).

- Arduino

   * L’arduino sera le cerveau de notre tank. Tous comme un automates il est composé de différente entrées et sorties. Pour ce projet nous utiliserons l’arduino UNO, c’est surement le modèle d’arduino le plus répandu

- Shield USB

   * Dans le monde d’arduino, un « shield » est un additif qui vient se fixer dessus pour lui rajouter des fonctionnalité. Ici, la fonctionnalité  qu’il nous manque c’est le Bluetooth pour communiquer avec la manette de PS3. Un shield USB, permet donc à l’arduino de venir brancher un périphérique USB (perspicace).

- Dongle Bluetooth

   * Pour la communication Bluetooth nous allons utiliser un dongle Bluetooth. C’est un petit module USB.


- Manette de PS3

   * Pour le pilotage du tank, j’ai choisi de prendre une manette de play 3. Nous pouvons totalement le faire avec d’autre moyen (télécommande RC, autre manette Bluetooth, clavier, etc.) libre à vous de changer si l’envie vous prend.
- Châssis

   * Le châssis peut être fabriqué ou acheter. J’ai choisis d’en acheter un et suivant la suite de ce projet en fabriquer un.
- Pont en H

   * Un pont en H est un composant électronique permettant de contrôler (vitesse, sens, frein) des moteurs. J’ai pris une carte déjà toute faite sur banggood basé sur un IC L298 pouvant piloter deux moteur DC ou un moteur pas à pas. Le tout jusqu’à 2 [A]. Emetteur/récepteur infrarouge (obligatoire).Les « tirs » seront simulé par un laser IR, comme sur une télécommande de TV. La communication est un signal de 38[kHz] qui nous permet d’éviter les interférences des autres lumières ambiantes.