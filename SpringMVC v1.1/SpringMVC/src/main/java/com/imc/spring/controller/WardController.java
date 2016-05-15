package com.imc.spring.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Controller;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.imc.spring.model.Address;
import com.imc.spring.model.Ward;
import com.imc.spring.service.WardService;

@Controller

// @SessionAttributes("address")
public class WardController {
//	@Autowired
//	WardService wardServicde;
	// dependency injection of ward's service layer
	// private WardService wardService;

	@RequestMapping(value = "/wards", method = RequestMethod.GET)
	public String getWards(ModelMap map) {
//		List<Ward> wards = wardServicde.getWards();
//		map.addAttribute("wards", wards);
		return "wards";
	}

	// @RequestMapping(value = "/wards", method = RequestMethod.GET)
	// public String getWard(int id) {
	// return "ward/";
	// }
	// @ModelAttribute("address")
	// public

}
