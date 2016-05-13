package com.imc.spring.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.imc.spring.dao.WardDao;
import com.imc.spring.model.Ward;

@Service
@Transactional

public class WardServiceImpl implements WardService {

	@Autowired
	private WardDao wDao;

	@Override
	public Ward getWard(long Id) {

		return wDao.getWard(Id);
	}

	@Override
	public void addWard(Ward ward) {
		wDao.addWard(ward);
	}

	@Override
	public void updateWard(Ward ward) {
		wDao.updateWard(ward);

	}

	@Override
	public void deleteWard(long Id) {
		wDao.deleteWard(Id);
	}

	@Override
	public List<Ward> getWards() {
		return wDao.getWards();
	}

}
