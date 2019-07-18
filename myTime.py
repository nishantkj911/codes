class Time:
    startTime = [0, 0]
    endTime = [23, 59]
    def __init__(self, st = [0, 0], en = [23, 59]):
        self.startTime = st
        self.endTime = en

    def __iter__(self):
        self.start = self.startTime
        return self

    def __next__(self):
        self.start[1] += 10
        if self.start[1] >= 60:
            self.start[0] += 1
            self.start[1] -= 60

        if self.start[0] >= 24:
            self.start[0] -= 24

        if self.start[0] >= self.endTime[0] and self.start[1] > self.endTime[1]:
            raise StopIteration

        return self.toString(self.start)
        
    
    def toString(self, myList):
        hh = ""
        mm = ""
        if myList[0] < 10:
            hh = "0" + str(myList[0])
        else:
            hh = str(myList[0])

        if myList[1] < 10:
            mm = "0" + str(myList[1])
        else:
            mm = str(myList[1])

        return hh + ":" + mm

""" times = Time([0, 20], [12, 30])
for time in times:
    print(time) """