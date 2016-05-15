package com.imc.spring.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

@Controller
public class GeneralController {

	@RequestMapping(value = "/home", method = RequestMethod.GET)
	public String home(ModelMap map) {
		map.addAttribute("doctors","Doctors");
		map.addAttribute("patients","Patients");
		map.addAttribute("nurse","Nurses");
		map.addAttribute("wards","Wards");
		return "home";
	}

	@RequestMapping(value = "/login", method = RequestMethod.GET)
	public String login() {
		return "login";
	}

	@RequestMapping(value = "/loginfailed", method = RequestMethod.GET)
	public String loginFailed(ModelMap map) {
		map.addAttribute("error", "Username or Password is invalid!");
		return "login";
	}

	@RequestMapping(value = "/logout", method = RequestMethod.GET)
	public String logout() {
		return "login";
	}

	@RequestMapping(value = "/", method = RequestMethod.GET)
	public String goHome() {
		return "login";
	}

}
