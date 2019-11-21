import os

def disk_usage(path):
    print(path)
    sum = os.path.getsize(path)
    if(os.path.isdir(path)):
        for entry in os.listdir(path):
            sum += disk_usage(os.path.join(path,entry))
    return sum

print(disk_usage('/Users/andrewqu/Documents'))
