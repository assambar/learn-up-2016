### Как се работи с git?

#### Какво изобщо е git?!
Git e система за контрол на версиите на файлове. Използва се за... контрол на версиите на файлове. Например ако:
- 200 човека разработвате app за лютеница и 201-ви човек дойде и ви счупи приложението и добави майонеза вие ще можете да върнете проекта до момента преди да е била добавена майонезата. 
- Също така супер много улеснява добавянето на код в проекта - като 200 човека пипат едни и същи работи и никой не знае какво пипа другия много ясно, че може тея работи да се счупят.. git често ще пречи това да стане. Например разработвате лютеница и докато не гледате някой слага майонеза в буркана ви - тука git ще се размрънка преди да "пуснете боламача на пазара".

#### Ок, звучи полезно. Сега как да го ползвам това чудо?
Ами да ти кажа и аз не съм сигурен. Зубриш там някви команди като останалите и се надяваш да работи. Ако трябва да се опише в стъпки, те ще са следните:
- Инсталирай си git.
- Пиши команди.

#### Малко терминология:
- repository - място дето има код/някви пакети и мойш да качваш и да сваляш съответния код или пакети
- branch - в контекста на git т'ва е "клон" на проекта. Примерно имаш сайт за лютеница и двама решават, че ще го развиват в две различни насоки - единия ще продава лютеница, другия ще прави уроци как се прави лютеница и ето ти как един проект се цепи на две. Ти си избираш в кой клон ще работиш

#### Една идея концепция преди да зубрим командите:
git работи така. Отиаш да разглеждаш в github и глеаш проект - електронен магазин за лютеница на едро. Викаш си "Ба, искам и аз да работя" и ко прайш? Отваряш git и сваляш repository-то на проекта локално. Пишеш там две нощи, потиш се, запазваш промени локално с commit и като решиш че си готов пишеш едно push origin master и сичко от локално отива в глобално (в нета). Ся сички могат да ти гледат глупостите дето си писал и да правят и те същото - свалят си проекта локално, потят се две нощи и качват глобално. 

#### git команди за зубрене:
- git add <file>: с тая команда казваме на git, че въпросния файл ще искаме да се ъпдейтне в repository-то дето се намира в нета (а не локално). Примерно файла liutenicaOlineza.cpp сме го променяли и после като качваме цялата работа в нета да я видят сички искаме тоя файл да се качи: пишем git add liutenicaOlineza.cpp
- git pull origin master --rebase: зима сегашната версия от master клона от нета, слагая тука локално и с --rebase параметъра казва, че при commit сички наши промени ще се случат след последните промени от другите програмисти
- git commit: локално промени проекта, като добавиш своите собствени промени (идващи от указаните от тебе файлове с git add) в/у промените на другите (идващи от pull origin master --rebase). Ако махнете rebase параметъра проекта ще се раздели на две - едната част с вашите промени, а другата с промените на другите. Ние искаме една част - нашите промени СЛЕД промените на другите (и от там rebase - промените ни няма да се основават на досегашната локална версия, а на най-новата версия от нета)
- git push origin master: най-накрая се качва на master клона, че 200 команди изписахме.

##### TODO Добави повече интуиция как работи git след като сам я развиеш и оправи тук там ако си казал някоя голяма глупост (щото тва си го чел на прима виста). Също ако някой реши че стила на писане е неприемлив се замисли дали да не го опрайш.