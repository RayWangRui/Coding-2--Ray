import random
print('''
___________________________
|                          |
|   Double Six Dice Game   |
|__________________________|
''')

def get_count():
    count = 0
    while True:
        count = count + 1
        dice1 = random.randint(1,6)
        dice2 = random.randint(1,6)
        if dice1==6 and dice2==6:
            return count


player1 = input('player1 name ')
player1_count = get_count()

player2 = input('player2 name ')
player2_count = get_count()

print('start')

if player1_count > player2_count:
    print(player1,' wins')
elif player1_count < player2_count:
    print(player2, 'wins')
else:
    print('draw')
