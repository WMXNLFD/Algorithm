voted = {}
def check_voter(name):
    if voted.get(name):
        print('kick them out')
    else:
        #以 name 为名 存True 没存false
        voted[name] =True
        print('let them vote')

check_voter('Tom')
check_voter('mike')
check_voter('mike')
