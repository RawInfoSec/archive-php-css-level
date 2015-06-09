<script>
	
	// CSS-Level 1.0
	// 
	// Provides highly granular targeting of any platform, browser, or even version.
	// This allows us to target those really stubborn cross browser quirks that affect for example: only a Mac running Version 12 of Firefox.
	//
	// Works by adding classes to the body tag of the page.  e.g. body class = "Chrome Chrome2 ChromeMac Chrome2Mac Mac"
	// allows careful selection of precise versions on specific platforms.
	//
	// 20090811 - kev@silicon-vision.com
	
	// requires jquery
	$(document).ready(function(){
		var ua=navigator.userAgent;
		// Safari and Chrome userAgents are indistinguishable, use feature prodding to eliminate one of them.
		// used information from http://www.byond.com/forum/?post=53727 to get this working.
		<?php
			if (!strpos($_SERVER['HTTP_USER_AGENT'],"MSIE")) {
				echo '
					if (ua.indexOf("Safari") && escape(navigator.javaEnabled.toString()) == "function%20javaEnabled%28%29%20%7B%20%5Bnative%20code%5D%20%7D" ) {
						ua=ua.replace("Safari","Sxafari");
					}';
			}
		?>
		var rerr=/(Trident|Firefox|Opera|MSIE|Safari|Chrome|Opera|Camino|Android)[\/\s](\d+)\.\d+/
		browser=rerr.exec(ua);

		// 20131223 kevin@rawinfosec.com 
		// Added next part to allow unknown browsers to simply show up as Unknown v1.0. 
		// 		This was needed because IE11 switched from MSIE to Trident and it broke when browser[x]==null
			if (browser===null) {
				var browser = new Array();
				browser[1]="UnknownBrowser";
				browser[2]="1";
			}
		// end addition 20131223-kc
		
		$('body').addClass(browser[1]);
		if (browser[1]=="Safari") { $('body').addClass(browser[1]+Math.floor(browser[2]/100)); } else { $('body').addClass(browser[1]+browser[2]); }
		var ua=navigator.userAgent;
		var rerr=/(Windows|Mac|Linux)/
		platform=rerr.exec(ua);
		$('body').addClass(browser[1]+platform[1]);
		if (browser[1]=="Safari") { $('body').addClass(browser[1]+Math.floor(browser[2]/100)+platform[1]); } else { $('body').addClass(browser[1]+browser[2]+platform[1]); }
		$('body').addClass(platform[1]);
	});
</script>