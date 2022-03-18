## My Coding Two Final Project✌🏻

Project Description: 
This is a sound visualization project based on OF. Its main functions are to use different visual elements and make them produce dynamic effects. <br>
The dynamic generation and floating rhythm change accordingly with the frequency and rhythm of music.
Interaction between people and works: manipulate the mouse to interact with works.<br>

Inspiration: each song has a different meaning. When writing their own songs, the authors have different emotions and their stories.
Different melodies, rhythms and other characteristics of each song bring different feelings, sad, cheerful, solemn and enthusiastic...  
But everyone also feels different about the same music. Some people may sound sad about the same melody, but some people feel calm. 
Therefore, I want to visually enlarge the musical elements through sound visualization to enhance people's sensory experience of melody. 
Different from the shooting of traditional music MV, I think this neutral visual effect, without human emotional intervention factors of the storyline, can dynamically let people feel the music and think about melody with the most primitive visual elements.

Here is the video:

https://user-images.githubusercontent.com/91971211/159017330-af4cd4d1-e53a-4866-a0e7-d3e0a7ab829c.mov



I designed four visual dynamic elements to amplify the senses of music:
1. Traditional cylindrical sound wave:
 <img width="686" alt="截屏2022-03-18 下午12 52 09" src="https://user-images.githubusercontent.com/91971211/159008670-4c3ab3d6-12af-4dd5-8274-25ec7f9db844.png">
It can make the audience intuitively feel the song frequency, which is in line with the traditional user experience.<br><br>

2. Take the circle as the core and fluctuate radially around:
<img width="738" alt="截屏2022-03-18 下午12 52 41" src="https://user-images.githubusercontent.com/91971211/159008846-0f999da5-0b60-4d95-a700-84cfb3fc2e4a.png">
Strengthen visual visualization and increase the sensory experience
<br>

3. In the center of the circle, I added a square as particles to fluctuate with the music:
<img width="276" alt="截屏2022-03-18 下午1 33 38" src="https://user-images.githubusercontent.com/91971211/159013205-969749a1-1d19-4761-bbca-17c4959aa105.png">

Increase the visual center to make the visualization full.

4. Click to change the background color:
Users can choose the background emotion color suitable for the song according to their own emotions.
<img width="1107" alt="截屏2022-03-18 下午1 34 37" src="https://user-images.githubusercontent.com/91971211/159013231-b6845d94-7cd9-439e-ae54-7f0ece706d2a.png">
<img width="1120" alt="截屏2022-03-18 下午1 35 46" src="https://user-images.githubusercontent.com/91971211/159013242-410a7a83-229a-408a-be15-a0ec40647884.png">
<img width="1112" alt="截屏2022-03-18 下午1 34 50" src="https://user-images.githubusercontent.com/91971211/159013266-a46e3ffc-e43f-4689-8b3d-9cba4eefb2bf.png">

This project mainly uses C + + and opeanfreamworks. First, I chose an MP3 song I like the format file is placed in the bin folder so that it can be used in the project. The size of the window is defined in the main file, and the program runs. HPP file defines some variables that need to be used in the program and some functions in openframeworks, including drawing images, mouse clicking to change the background, and some floating-point data. Cpp file defines the background color, audio file loading, image transformation size data, etc.

