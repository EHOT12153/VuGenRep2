Action()
{

	lr_start_transaction("UC4_LoginLogout");

/*Correlation comment - Do not change!  Original value='136363.399432969HAVtVQcpDfiDDDDDtcAifpVftVf' Name ='userSession' Type ='ResponseBased'*/
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

	lr_think_time(23);
	
	lr_end_transaction("loginPage", LR_AUTO);
	


	login();
	
	



	

	lr_end_sub_transaction("UC4_LoginLogout", LR_AUTO);

	return 0;
}