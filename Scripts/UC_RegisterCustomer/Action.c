Action()
{

	lr_start_transaction("UC5_CustomerRegistration");
		
	
	
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

	lr_think_time(21);
	
	lr_end_transaction("loginPage", LR_AUTO);
	
	lr_start_transaction("signUpPage");

		

	web_reg_find("Text=Please choose a username and password combination for your account.",
		LAST);

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(24);
	
	lr_end_transaction("signUpPage", LR_AUTO);
	
	
	lr_start_transaction("registrationData");
	
	web_reg_find("Text=Thank you, <b>{l1}{l2}{l3}{l4}</b>, for registering and welcome to the Web Tours family.",
		LAST);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=password", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=passwordConfirm", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=firstName", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=lastName", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=address1", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=address2", "Value={l1}{l2}{l3}{l4}", ENDITEM, 
		"Name=register.x", "Value=46", ENDITEM, 
		"Name=register.y", "Value=4", ENDITEM, 
		LAST);
	
	lr_end_transaction("registrationData",LR_AUTO);

	
	lr_think_time(7);
	
	lr_start_transaction("pageAfterRegistaration");

	web_reg_find("Text=Welcome, <b>{l1}{l2}{l3}{l4}</b>, to the Web Tours reservation pages.",
		LAST);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("pageAfterRegistaration",LR_AUTO);
	
	lr_end_transaction("UC5_CustomerRegistration", LR_AUTO);

	return 0;
}