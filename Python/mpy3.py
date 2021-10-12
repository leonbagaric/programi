from __future__ import unicode_literals
from youtubesearchpython import VideosSearch
from pytube import YouTube
import os
import pathlib
import youtube_dl
import tkinter.filedialog
import tkinter as tk




#NE RADI BEZ FFMPEG.EXE I FFPROBE.EXE




root = tk.Tk()
root.withdraw()

resultlist = []
namelist = []
numinput = 0
yt = YouTube('https://www.youtube.com/watch?v=3IT2Cc_5WxE')


def sch():
    global numinput
    global yt
    
    print('Enter your search term: ')

    nameinput = input(str())

    print(' ')
    
    search = VideosSearch(nameinput, limit = 15)

    r = search.result()

    i = 0
    
    for d in r['result']:
        print(str(i+1)+ ' ' + d['title'])
        namelist.append(d['title'])
        resultlist.append(d['link'])
        i = i + 1

    print(' ')
    print('Enter a number or 0 to search again:')

    numinput = int(input())


    if numinput == 0 or numinput > 15 or numinput < 0:
        os.system('cls')
        sch()
    
    else:
        yt = YouTube(resultlist[numinput-1])
        return numinput, yt

def av():
    global numinput
    global yt
    t = input(str())

    #destination = str(pathlib.Path(__file__).parent.absolute())+'\\'
    directory = tkinter.filedialog.askdirectory()
    
    ydl_opts = {
        'format': 'bestaudio/best',
        'outtmpl': directory+'/%(title)s.%(ext)s',
        'postprocessors': [{
            'key': 'FFmpegExtractAudio',
            'preferredcodec': 'mp3',
            'preferredquality': '192'
        }],
        'postprocessor_args': [
            '-ar', '16000'
        ],
        'prefer_ffmpeg': True,
        'keepvideo': False
    }
    print(' ')
    if t == 'a' or t == 'A':
        print('Downloading')
        with youtube_dl.YoutubeDL(ydl_opts) as ydl:
            ydl.download([resultlist[numinput-1]])
        print('Done')

    elif t == 'v' or t == 'V':
        dl = yt.streams.get_highest_resolution()
        print('Downloading')
        dl.download(directory)
        print('Done')

    else:
        print('Unknown, please repeat: ')
        av()

sch()
print(' ')
print('Type v for video or a for audio: ')
av()
