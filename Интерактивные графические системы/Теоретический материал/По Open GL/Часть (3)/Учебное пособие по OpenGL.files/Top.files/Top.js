var last_tohide = true;
function HideMenu(btn)
{
	var frameSet = window.parent.document.getElementById("treeshower");
	if (frameSet != null)
	{
		frameSet.cols = "0,*";
		last_tohide = false;
	}
	
	var aHider = document.getElementById("aHider");
	aHider.href = "javascript:ShowMenu(true);";
	Img = aHider.childNodes[0];
	Img.title = "Показать меню";
	if (btn == true)
		Img.src = "/Frame/Images/showmenu_.gif";
	else	
		Img.src = "/Frame/Images/showmenu.gif";

}

function ShowMenu(btn)
{
	var frameSet = window.parent.document.getElementById("treeshower");
	if (frameSet != null)
	{
		if (!last_tohide)
		{
			frameSet.cols = "*,75%";
			last_tohide = true;
			var aHider = document.getElementById("aHider");
			aHider.href = "javascript:HideMenu(true);";
			Img = aHider.childNodes[0];
	        	Img.title="Убрать меню";
			if (btn == true)
				Img.src="/Frame/Images/hidemenu_.gif";
			else	
				Img.src="/Frame/Images/hidemenu.gif";
		}
	}
}

function Lighten(img)
{
	src = img.src;
	if (-1 != src.lastIndexOf("."))
		img.src = src.substring(0,src.lastIndexOf(".")) + "_.gif";
}

function Darken(img)
{
	src = img.src;
	if (-1 != src.lastIndexOf("_"))
		img.src = src.substring(0,src.lastIndexOf("_")) + ".gif";
}

function Locate()
{
	ShowMenu(false);
	loc = window.parent.frames["frmMain"].location;
	window.parent.frames["frmTree"].location =
		"/toc/?url=" + loc.pathname + loc.search;
}

function GetURL()
{
	var loc = window.parent.frames["frmMain"].location;
	var lp = loc.pathname;
	lp = lp.substr(1,lp.length);
	window.top.location.replace("/?" + lp + loc.search);
}

function DocumentOnMouseOver()
{
	if (is_ie5up)
	{
		var cblue = new Array();
		var cgrey = new Array();
		var iblue = new Array();
		var igrey = new Array();

		cblue[0]="#65A7CB"; iblue[0]="#d5f2ff";
		cblue[1]="#69ABCF"; iblue[1]="#d7f4ff";
		cblue[2]="#6DAFD3"; iblue[2]="#d9f6ff";
		cblue[3]="#71B3D7"; iblue[3]="#e4faff";
		cblue[4]="#75B7DB"; iblue[4]="#f2fdff";

		cgrey[0]="#7da4be"; igrey[0]="#e5f0f2";
		cgrey[1]="#7eaac5"; igrey[1]="#ebf7f8";
		cgrey[2]="#83aec9"; igrey[2]="#f3fdff";
		cgrey[3]="#87b4cd"; igrey[3]="#f5feff";
		cgrey[4]="#8ab8d2"; igrey[4]="#f7ffff";

		glow(window.event.srcElement,"bluebtn",true,cblue,iblue);     
		glow(window.event.srcElement,"greybtn",true,cgrey,igrey);     
		glow(window.event.srcElement.parentElement,"bitmapbtn",true,cblue,iblue);     
	}
}

function DocumentOnMouseOut()
{
	if (is_ie5up)
	{
		dim(window.event.srcElement,"bluebtn");
		dim(window.event.srcElement,"greybtn");
		dim(window.event.srcElement.parentElement,"bitmapbtn");
	}
}

var B = new Array();
var num=0;
var GLOWING=1, LIT=2, FADING=3;
var GLOWSPEED=30, FADESPEED=50;

function glow(elem,classname,border,cols,inks)
{
	if (elem.parentElement && elem.parentElement.className == classname)
		elem=elem.parentElement;

	if (elem.className == classname)
	{
		num++;
		B[num] = elem;
		B[num].stat=GLOWING;
		B[num].cols=cols;
		B[num].inks=inks;
		B[num].border=border;
		B[num].i=0;

		fadein();
	}
}

function fadein()
{
	for (n=1;n<=num;n++)
	{
		if (B[n].stat==GLOWING)
		{
			B[n].style.color=B[n].inks[B[n].i];

			if (B[n].border)
				B[n].style.backgroundColor=B[n].cols[B[n].i];

			B[n].i++;

			if (B[n].i<=5) 
				setTimeout("fadein()",GLOWSPEED);
			else 
				B[n].stat=LIT;
		}
	}
}

function dim(elem,classname)
{
	if (elem.parentElement && elem.parentElement.className == classname)
		elem=elem.parentElement;

	if (num>0)
	{
		n=0;
		while (B[n] != elem && n <= num+1)
			n++;
		if (n > num)
			return;
		B[n].stat = FADING;
		fadeout();
	}
}

function fadeout(cols,inks)
{
	for (n=1; n<=num; n++)
	{
		if (B[n].stat == FADING)
		{
			B[n].style.color = B[n].inks[B[n].i];

			if (B[n].border)
				B[n].style.backgroundColor = B[n].cols[B[n].i];

			B[n].i--;
   
			if (B[n].i >= 0) 
				setTimeout("fadeout()",FADESPEED);
			else 
			{
				B[n] = B[num];
				num--; 
			} 
		}
	}
}
