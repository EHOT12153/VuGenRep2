Action()
{
	web_set_max_html_param_len("99999999");

	lr_start_transaction("UC3_DeleteTicket");

/*Correlation comment - Do not change!  Original value='136363.35471851HAVtVQApAfiDDDDDtcAifpVtADf' Name ='userSession' Type ='ResponseBased'*/
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

	web_reg_find("Text=Web Tours Navigation Bar",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

		
	

	lr_think_time(10);
	
	lr_end_transaction("loginPage", LR_AUTO);

	login();

	lr_start_transaction("checkItinerary");
	

	web_reg_find("Text={firstname} {lastname}",LAST);

	

	web_reg_save_param("flightID",
		"LB=flightID\" value=\"",
		"RB=\"",
		LAST);
	
//	web_reg_save_param("checkbox",
//		"LB=checkbox\"name=\"",
//		"RB=\"",
//		"Ord=ALL",
//		LAST);

	

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
//	lr_save_string(lr_paramarr_random("checkbox"), "random_checkbox");
//	lr_save_string(lr_paramarr_idx("flightID", atoi(lr_paramarr_random("checkbox"))), " randomflightID");


	lr_end_transaction("checkItinerary",LR_AUTO);

	lr_think_time(35);

	lr_start_transaction("deleteTicket");
	

	

	web_reg_find("Fail=Found",
		"Text=randomflightID",
		LAST);

	
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t8.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		 "Name=removeFlights.x", "Value=33", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("deleteTicket",LR_AUTO);

	lr_think_time(28);

	logout();
	
	lr_end_transaction("UC3_DeleteTicket", LR_AUTO);

	return 0;
}