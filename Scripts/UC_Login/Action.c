Action()
{

	lr_start_transaction("UC_Login");
/*Correlation comment - Do not change!  Original value='136482.467962738HAcADVzpQtfiDDDDtcVcVpQAVzHf' Name ='userSession' Type ='ResponseBased'*/
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=*/nav.pl*",
		LAST);
		
lr_start_transaction("loginPage");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(19);
	
	lr_end_transaction("loginPage", LR_AUTO);



	login();
	

	lr_start_transaction("checkItinerary");
	
	
	web_reg_find("Text=Flights List",
	            LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("checkItinerary",LR_AUTO);

	lr_think_time(33);

	lr_start_transaction("flights");
	
	web_reg_find("Text=Flight Selections",
	            LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("flights", LR_AUTO);
	
	lr_end_transaction("UC_Login", LR_AUTO);

	return 0;
}