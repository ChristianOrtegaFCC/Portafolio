import { ComponentFixture, TestBed } from '@angular/core/testing';

import { H } from './h';

describe('H', () => {
  let component: H;
  let fixture: ComponentFixture<H>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [H]
    })
    .compileComponents();

    fixture = TestBed.createComponent(H);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
