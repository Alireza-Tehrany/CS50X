# -*- coding: utf-8 -*-

import speech_recognition as sr
audiofile = input('Enter the name of audio file with format: ')
r = sr.Recognizer()

audio_file = sr.AudioFile(audiofile)
with audio_file as source:
    try:
        #r.adjust_for_ambient_noise(source)
        audio_data = r.record(source)
        # recognize (convert from speech to text)
        text = r.recognize_google(audio_data,language='en-US')

    except Exception as e:
        print("Error ",e)
##########################################
text = text.lower()
myspeech=text.split(" ")
list1 = myspeech
print('\n' + f'Your text is: ' + text + '\n')
# print(list)
##########################################
A = ['alyssa', 'ticket' , 'concert', 'seat', 'friendship', 'selena',
     'mettalica', 'jlo', 'mercedes', 'bmw', 'wine', 'guitar', 'piano',
     'drums', 'band', 'expensive', 'cheap', 'chocolate']
counter_dict = {}

for i in list1:
        for l in A:
            if i[0:3] == l[0:3]:
                for k in list(i):
                    if k not in list(l):
                        n = i.index(k)
                        h = list1.index(i)
                        list1[h] = i[0:n] + i [n+1:]


for i in list1:
    if i in A:
        if i not in counter_dict:
            counter_dict[i] = 1
        else:
            counter_dict[i] += 1
    else:
        for j in A:
            if j not in counter_dict:
                counter_dict[j] = 0





print('Final counters are: \n')

for i in counter_dict:
    print('\n' ,i,counter_dict[i])