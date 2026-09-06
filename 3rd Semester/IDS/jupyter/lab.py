players_data = [
"id:1,name:Babar Azam,role:Batsman,avg:58.4,strike_rate:88,fitness:92,feedback:Excellent",
"id:2,name:Shaheen Afridi,role:Bowler,avg:12.5,strike_rate:85,fitness:88,feedback:Helpful",
"id:3,name:Shadab Khan,role:All-Rounder,avg:35.6,strike_rate:120,fitness:80,feedback:Very Good",
"id:4,name:Fakhar Zaman,role:Batsman,avg:45.2,strike_rate:98,fitness:70,feedback:Average",
"id:5,name:Muhammad Rizwan,role:Wicket-Keeper,avg:52.8,strike_rate:93,fitness:95,feedback:Excellent",

"id:6,name:Imam-ul-Haq,role:Batsman,avg:48.7,strike_rate:82,fitness:86,feedback:Very Good",
"id:7,name:Hasan Ali,role:Bowler,avg:15.4,strike_rate:90,fitness:78,feedback:Helpful",
"id:8,name:Haris Rauf,role:Bowler,avg:10.2,strike_rate:85,fitness:89,feedback:Excellent",
"id:9,name:Iftikhar Ahmed,role:All-Rounder,avg:33.1,strike_rate:115,fitness:81,feedback:Good",
"id:10,name:Azam Khan,role:Wicket-Keeper,avg:27.5,strike_rate:140,fitness:65,feedback:Average",

"id:11,name:Sarfaraz Ahmed,role:Wicket-Keeper,avg:40.3,strike_rate:92,fitness:72,feedback:Helpful",
"id:12,name:Mohammad Nawaz,role:All-Rounder,avg:29.8,strike_rate:110,fitness:84,feedback:Good",
"id:13,name:Usama Mir,role:Bowler,avg:18.6,strike_rate:95,fitness:75,feedback:Average",
"id:14,name:Abdullah Shafique,role:Batsman,avg:47.3,strike_rate:90,fitness:90,feedback:Excellent",
"id:15,name:Shan Masood,role:Batsman,avg:42.1,strike_rate:83,fitness:88,feedback:Very Good",

"id:16,name:Abrar Ahmed,role:Bowler,avg:12.0,strike_rate:70,fitness:77,feedback:Helpful",
"id:17,name:Mohammad Haris,role:Batsman,avg:36.8,strike_rate:130,fitness:85,feedback:Excellent",
"id:18,name:Khushdil Shah,role:All-Rounder,avg:28.9,strike_rate:118,fitness:74,feedback:Average",
"id:19,name:Saim Ayub,role:Batsman,avg:33.7,strike_rate:132,fitness:83,feedback:Good",
"id:20,name:Shaheen Shah Jr,role:Bowler,avg:9.5,strike_rate:65,fitness:68,feedback:Average",

"id:21,name:Usman Qadir,role:Bowler,avg:14.4,strike_rate:88,fitness:80,feedback:Helpful",
"id:22,name:Mohammad Wasim Jr,role:Bowler,avg:18.1,strike_rate:105,fitness:91,feedback:Very Good",
"id:23,name:Agha Salman,role:All-Rounder,avg:39.6,strike_rate:98,fitness:87,feedback:Good",
"id:24,name:Zaman Khan,role:Bowler,avg:8.3,strike_rate:60,fitness:82,feedback:Average",
"id:25,name:Shoaib Malik,role:All-Rounder,avg:41.2,strike_rate:122,fitness:76,feedback:Excellent",

"id:26,name:Haider Ali,role:Batsman,avg:32.0,strike_rate:128,fitness:79,feedback:Helpful",
"id:27,name:Asif Ali,role:Batsman,avg:28.4,strike_rate:150,fitness:73,feedback:Average",
"id:28,name:Rumman Raees,role:Bowler,avg:11.8,strike_rate:72,fitness:67,feedback:Good",
"id:29,name:Shanawaz Dahani,role:Bowler,avg:13.2,strike_rate:85,fitness:88,feedback:Very Good",
"id:30,name:Umar Akmal,role:Batsman,avg:37.9,strike_rate:125,fitness:69,feedback:Average"
]
print("Task 1:")
def structure_data(players_data):
    player=[]
    for p in players_data:
        parts=p.split(',')
        d={}
        for par in parts:
            key,val=par.split(':')
            if key in ['id']:
                val=int(val) 
            if key in ['avg','strike_rate','fitness']:
                val=float(val) 
            d[key]=val
        player.append(d)
    return player     
data=structure_data(players_data) 
print(data)


print("Task 2:")
def countPlayers(data):
    count=0
    for d in data:
        if d['name']:
            count+=1
    return count
print("Count of Players: ",countPlayers(data))


print("Task 3:")
def fitness_summary(data):
    bat=[]
    bowl=[]
    allr=[]
    wk=[]
    for d in data:
        if d['role']=="Batsman":
            bat.append(d['fitness'])
        elif d['role']=="All-Rounder":
            allr.append(d['fitness'])
        elif d['role']=="Bowler":
            bowl.append(d['fitness'])
        elif d['role']=="Wicket-Keeper":
            wk.append(d['fitness'])
    avg_bat=sum(bat)/len(bat)
    avg_bowl=sum(bowl)/len(bowl)
    avg_all=sum(allr)/len(allr)
    avg_wk=sum(wk)/len(wk)
    print("Average Fitness Level of Batsman: ",avg_bat)
    print("Average Fitness Level of Bowler: ",avg_bowl)
    print("Average Fitness Level of AllRounder: ",avg_all)
    print("Average Fitness Level of Wicket-Keeper: ",avg_wk)
fitness_summary(data)


print("Task 4:")
def low_fitness(data):
    names=[]
    for d in data:
        if d['fitness']>=75 and d['fitness']<80 :
            names.append(d['name'])
    return names
print("low fitness level player: ",low_fitness(data))


print("Task 5:")
def highest_avg(data):
    avg=("",0)
    for d in data:
        if avg[1]<d['avg']:
            a=d['name']
            b=d['avg']
            avg=(a,b)
    return avg
print("Highest Average: ",highest_avg(data))


print("Task 6:")
def lowest_avg(data):
    avg=("name",1000)
    for d in data:
        if avg[1]>d['avg']:
            a=d['name']
            b=d['avg']
            avg=(a,b)
    return avg
print("lowest Average: ",lowest_avg(data))


print("Task 7:")
def high_strikerate(data):
    names=[]
    for d in data:
        if d['strike_rate']>95:
            names.append(d['name'])
    return names
print("Players with Strike_rate >95: ",low_fitness(data))


print("Task 8:")
def countRoles(data):
    count=0
    roles=[]
    for d in data:
        if d['role'] not in roles:
            roles.append(d['role'])
            count+=1
    print("Count of Roles: ",count)
    print("Roles: ",roles)
countRoles(data)


print("Task 9:")
def feedbacks(data):
    exe=[]
    vgood=[]
    help=[]
    avg=[]
    for d in data:
        if d['feedback']=="Excellent":
            exe.append(d['name'])
        elif d['feedback']=="Very Good":
            vgood.append(d['name'])
        elif d['feedback']=="Helpful":
            help.append(d['name'])
        elif d['feedback']=="Average":
            avg.append(d['name'])
    print("Count of Exellent: ",len(exe))
    print("Count of Very Good: ",len(vgood))
    print("Count of Helpful: ",len(help))
    print("Count of Average: ",len(avg))
feedbacks(data)


print("Task 10:")
def overall_avg(data):
    avg=[]
    for d in data:
        avg.append(d['avg'])
    avgg=sum(avg)/len(avg)
    return avgg
print("overall average of team: ",overall_avg(data))


print("Task 11:")
def fitness_grade(data):
    for d in data:
        if d['fitness'] >=90:
            d['fitness_grade']="A"
        elif d['fitness'] >=80 and d['fitness'] <90:
            d['fitness_grade']="B"
        elif d['fitness'] >=70 and d['fitness'] <80:
            d['fitness_grade']="C"
        else:
            d['fitness_grade']="D"
    return data
print(fitness_grade(data))


print("Task 12:")
def improved_strike_rate(data):
    new=[]
    for d in data:
        n=d['name']
        sr = d['strike_rate']*110/100
        new.append((n,sr))
    return new
print(improved_strike_rate(data))


print("Task 13:")
def role_wise_avg_fitness(data):
    bat=[]
    bowl=[]
    allr=[]
    wk=[]
    for d in data:
        if d['role']=="Batsman":
            bat.append(d['fitness'])
        elif d['role']=="All-Rounder":
            allr.append(d['fitness'])
        elif d['role']=="Bowler":
            bowl.append(d['fitness'])
        elif d['role']=="Wicket-Keeper":
            wk.append(d['fitness'])
    avg_bat=sum(bat)/len(bat)
    avg_bowl=sum(bowl)/len(bowl)
    avg_all=sum(allr)/len(allr)
    avg_wk=sum(wk)/len(wk)
    print(f"Role: Batsman Count: {len(bat)}  Avg Fitness Level: ",avg_bat)
    print(f"Role: Bowler Count: {len(bowl)}  Avg Fitness Level: ",avg_bowl)
    print(f"Role: All-Rounder Count: {len(allr)}  Avg Fitness Level: ",avg_all)
    print(f"Role: Wicket-Keeper Count: {len(wk)}  Avg Fitness Level: ",avg_wk)
role_wise_avg_fitness(data)


print("Task 14:")
def strong_batsman(data):
    strong={}
    for d in data:
        if d['avg']>=50:
            strong[d['name']]=d['avg']
    return strong
print("Strong batsmans of team: ",strong_batsman(data))


print("Task 15:")
def fitness_risk(data):
    player={}
    for d in data:
        if d['fitness'] <75:
            d['fitness_tag']="High Risk"
            player[d['name']]=d['fitness_tag']
        else:
            d['fitness_tag']="OK"
            player[d['name']]=d['fitness_tag']
    return player
print("Players With Fitness Tag: ",fitness_risk(data))


print("Task 16:")    
def sort_by_avg(data):
    data.sort(key=lambda x:x['avg'],reverse=True)
    return data
sorted_data = sort_by_avg(data)
for p in sorted_data:
    print(p['name'], p['avg'])


print("Task 17:")
def undervalued(data):
    under=[]
    for d in data:
        if d['avg']>=50 and d['feedback']!="Excellent":
            under.append(d['name'])
    return under
print("under valued performers: ",undervalued(data))


print("Task 18:")
def count_helpful(data):
    count=0
    for d in data:
        d['feedback']=d['feedback'].lower()
        if d['feedback']=="helpful":
            count+=1
    return count
print("count of helpful players: ",count_helpful(data))


print("Task 19:")
def role_balance(data):
    count_bat=0
    count_bowl=0
    count_wk=0
    count_allr=0
    for d in data:
        if d['role']=="Batsman":
            count_bat+=1
        elif d['role']=="Bowler":
            count_bowl+=1
        elif d['role']=="Wicket-Keeper":
            count_wk+=1
        elif d['role']=="All-Rounder":
            count_allr+=1
    if count_bat>=2 and count_bowl>=1 and count_wk>=1 and count_allr>=1:
        return True
    else:
        return False
print("Is the team Balanced : ",role_balance(data))


print("Task 20:")
def player_summary(data):
    print("Player Summary:")
    for d in data:
        print(f"Name: {d['name']} Role: {d['role']} Average: {d['avg']} Strike-Rate: {d['strike_rate']} Feedback: {d['feedback']} Fitness: {d['fitness']}")
player_summary(data)