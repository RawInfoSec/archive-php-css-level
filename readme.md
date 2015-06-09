# Old Code: 
### Responsive design has gotten pretty good at eliminating the need for things like this, however it is still useful for those really hard to target bugs affecting only a single version of a single browser on a single platform

# CSS Level
### (PHP version)

	// Provides **highly granular targeting** of any platform, browser, or even version.
	// This allows us to target those really stubborn cross browser quirks that affect for example: only a Mac running Version 12 of Firefox.
	//
	// Works by adding classes to the body tag of the page.  e.g. body class = "Chrome Chrome2 ChromeMac Chrome2Mac Mac"
	// allows careful selection of precise versions on specific platforms.
	//
	// 20090811 - kev@silicon-vision.com

##### Note:
    // 20131223 kevin@rawinfosec.com 
		// Added next part to allow unknown browsers to simply show up as Unknown v1.0. 
		// 		This was needed because IE11 switched from MSIE to Trident and it broke when browser[x]==null
		

#### Example body tag in Firefox
![alt text](https://raw.githubusercontent.com/RawInfoSec/php-css-level/master/examples-in-use-(images)/example-Firefox.png)

#### Example body tag in Chrome
![alt text](https://raw.githubusercontent.com/RawInfoSec/php-css-level/master/examples-in-use-(images)/example-Chrome.png)


