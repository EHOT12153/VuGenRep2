Action()
{

/*Correlation comment - Do not change!  Original value='136355.491616039HAVDHifpztcAicpHVDz' Name ='userSession' Type ='ResponseBased'*/

lr_start_transaction("UC1_BuyTicket");

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

	web_reg_find("Text=Web Tours",
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
		
		lr_end_transaction("loginPage",LR_AUTO);
		


	lr_think_time(19);
	
	login();


	lr_start_transaction("flights");
	
	web_reg_find("Text=Web Tours Navigation Bar",LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(4);
	
	lr_end_transaction("flights", LR_AUTO);
	
	lr_start_transaction("typeData");
	
	
	
	web_reg_find("Text=From",
		LAST);

/*Correlation comment - Do not change!  Original value='020;338;05/06/2023' Name ='outboundFlight' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=outboundFlight",
//		"TagName=input",
//		"Extract=value",
//		"Name=outboundFlight",
//		"Type=radio",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		LAST);
		
		web_reg_save_param("outboundFlight",
		"LB=name=\"outboundFlight\" value=\"",
		"RB=\"",
		"Ord=ALL",
		LAST);
		
		
		
//strcpy(flightVal,lr_eval_string(lr_paramarr_random("outboundFlight")));

//lr_save_string((lr_paramarr_random("outboundFlight")),"randomFlight");

//lr_paramarr_idx(atoi(lr_paramarr_random("outboundFlight")));
 

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={DepCity}", ENDITEM,
		"Name=departDate", "Value={DepDate}", ENDITEM,
		"Name=arrive", "Value={ArrCity}", ENDITEM,
		"Name=returnDate", "Value={ArrDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatPref", "Value={seatingpref}", ENDITEM,
		"Name=seatType", "Value={typeseat}", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		"Name=findFlights.x", "Value=53", ENDITEM,
		"Name=findFlights.y", "Value=13", ENDITEM,
		LAST);
		
		lr_save_string((lr_paramarr_random("outboundFlight")),"randomFlight");

	lr_end_transaction("typeData",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("chooseFlight");
	
	web_reg_find("Text=Flight Reservation",LAST);
	

	web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={randomFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={typeseat}", ENDITEM,
		"Name=seatPref", "Value={seatingpref}", ENDITEM,
		"Name=reserveFlights.x", "Value=33", ENDITEM,
		"Name=reserveFlights.y", "Value=12", ENDITEM,
		LAST);

	lr_end_transaction("chooseFlight",LR_AUTO);

	lr_think_time(65);

	lr_start_transaction("personalData");
	
	web_reg_find("Text=Customer Name header",LAST);

	web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={FirstName}", ENDITEM,
		"Name=lastName", "Value={LastName}", ENDITEM,
		"Name=address1", "Value={streetadd}", ENDITEM,
		"Name=address2", "Value={zip}", ENDITEM,
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM,
		"Name=creditCard", "Value={CardNumber}", ENDITEM,
		"Name=expDate", "Value={expdate}", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=seatType", "Value={typeseat}", ENDITEM,
		"Name=seatPref", "Value={seatingpref}", ENDITEM,
		"Name=outboundFlight", "Value={randomFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		"Name=buyFlights.x", "Value=33", ENDITEM,
		"Name=buyFlights.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("personalData",LR_AUTO);

	lr_think_time(53);
	
	lr_start_transaction("checkItinerary");
	
	web_reg_find("Text={FirstName} {LastName}",LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("checkItinerary", LR_AUTO);

	logout();
	
	
	
	lr_end_transaction("UC1_BuyTicket",LR_AUTO);

	return 0;
}