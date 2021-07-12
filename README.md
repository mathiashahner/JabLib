# JabLib

Functions that can be useful!

### Compiler Installation:

- Go to site: https://sourceforge.net/projects/mingw/ and click in "Download"
- Run the downloaded file and proceed through the installation screens
- When the download of the tool it finishes click "Continue"
- Mark the option "mingw32-gcc-g++" for installation, go to menu "Installation" e "Apply Changes"

![image](https://user-images.githubusercontent.com/62864819/125217377-dd421780-e296-11eb-8a96-f196ce1f3084.png)

- Click on the "Apply" button and wait the download finish


### Configuration of the environment variables (Windows):

- Search for "Environment Variables" on the Start Menu

![image](https://user-images.githubusercontent.com/62864819/125222676-d7513400-e2a0-11eb-9da2-0d24fb10c77d.png)

- Click in "Environment Variables...", select "Path", click in "Edit", "New" and paste "C:\MinGW\bin" (or the path where the compiler is installed)

![image](https://user-images.githubusercontent.com/62864819/125222338-306c9800-e2a0-11eb-9a90-d44d315359db.png)

- Click on the "OK" buttons of the screens


### Configuration command "Make" (Windows):

- Press the keys "Win + R", type "cmd" and press "Enter"
- Paste the command line bellow:

<code>choco install make</code>